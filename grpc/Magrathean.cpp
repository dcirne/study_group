#include "hitchhiker.pb.h"
#include "hitchhiker.grpc.pb.h"

#include <grpcpp/grpcpp.h>
#include <iostream>
#include <memory>
#include <string>

class Magrathean final {
    std::unique_ptr<hitchhiker::Computer::Stub> computerStub;

  public:
    Magrathean(std::shared_ptr<grpc::Channel> channel) : computerStub(hitchhiker::Computer::NewStub(channel)) {}
    
    std::string askQuestion() {
        grpc::ClientContext clientContext;
        hitchhiker::Question question;
        hitchhiker::Answer answer;

        question.set_text("What is answer to the ultimate question of life, the universe, and everything?");

        grpc::Status status = computerStub->Inquire(&clientContext, question, &answer);

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

    std::string theAnswer = magrathean.askQuestion();
    std::cout << theAnswer << std::endl;

    return 0;
}

