#include "hitchhiker.pb.h"
#include "hitchhiker.grpc.pb.h"

#include <grpcpp/grpcpp.h>
#include <iostream>
#include <memory>
#include <string>

class Magrathean final {
    std::unique_ptr<hitchhiker::Computer::Stub> _computerStub;
    int _uniqueRequestId;

  public:
    Magrathean(std::shared_ptr<grpc::Channel> channel) : _computerStub(hitchhiker::Computer::NewStub(channel)) {
        _uniqueRequestId = 0;
    }

    std::string askQuestion(const std::string questionText) {
        grpc::ClientContext clientContext;
        grpc::CompletionQueue completionQueue;
        grpc::Status status;

        hitchhiker::Question question;
        question.set_text(questionText);
        hitchhiker::Answer answer;

        std::unique_ptr<grpc::ClientAsyncResponseReader<hitchhiker::Answer>> answerRPC(_computerStub->PrepareAsyncInquire(&clientContext, question, &completionQueue));
        answerRPC->StartCall();
        ++_uniqueRequestId;
        std::cout << "Unique request id: " << _uniqueRequestId << " - ";
        answerRPC->Finish(&answer, &status, (void *)&_uniqueRequestId);

        void *receivedUniqueRequestId;
        bool success = false;
        completionQueue.Next(&receivedUniqueRequestId, &success);

        if (*((int *)receivedUniqueRequestId) != _uniqueRequestId) {
            std::cout << "Received response from a different request." << std::endl;
        }

        if (status.ok()) {
            return answer.text();
        } else {
            std::cout << "gRPC error. Code: " << status.error_code() << ", message: " << status.error_message() << std::endl;
            return "Deep Thought is not available.";
        }
    }
};


int main(int argc, char **argv) {
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:4242", grpc::InsecureChannelCredentials());
    Magrathean magrathean(channel);

    std::string theAnswer = magrathean.askQuestion("What is answer to the ultimate question of life, the universe, and everything?");
    std::cout << theAnswer << std::endl;

    theAnswer = magrathean.askQuestion("How many roads must a man walk down?");
    std::cout << theAnswer << std::endl;

    return 0;
}

