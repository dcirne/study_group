#include "hitchhiker.pb.h"
#include "hitchhiker.grpc.pb.h"

#include <grpcpp/grpcpp.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Magrathean final {
    std::unique_ptr<hitchhiker::Computer::Stub> computerStub;

  public:
    Magrathean(std::shared_ptr<grpc::Channel> channel) : computerStub(hitchhiker::Computer::NewStub(channel)) {}

    std::vector<hitchhiker::Answer> askQuestions(const std::vector<hitchhiker::Question> questions) {
        grpc::ClientContext clientContext;
        std::vector<hitchhiker::Answer> answers;
        answers.reserve(questions.size());

        std::unique_ptr<grpc::ClientReaderWriter<hitchhiker::Question, hitchhiker::Answer>> stream(computerStub->Inquires(&clientContext));
        // auto stream = std::make_unique<grpc::ClientReaderWriter<hitchhiker::Question, hitchhiker::Answer>>(computerStub->Inquires(&clientContext));

        for (const auto &question : questions) {
            stream->Write(question);
        }
        stream->WritesDone();

        hitchhiker::Answer answer;
        while (stream->Read(&answer)) {
            answers.push_back(answer);
        }

        grpc::Status status = stream->Finish();
        if (status.ok()) {
            return answers;
        } else {
            std::cout << "gRPC error. Code: " << status.error_code() << ", message: " << status.error_message() << std::endl;
            return std::vector<hitchhiker::Answer>();
        }
    }
};

int main(int argc, char **argv) {
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:4242", grpc::InsecureChannelCredentials());
    Magrathean magrathean(channel);

    hitchhiker::Question q1;
    q1.set_text("What is answer to the ultimate question of life, the universe, and everything?");

    hitchhiker::Question q2;
    q2.set_text("How many roads must a man walk down?");

    hitchhiker::Question q3;
    q3.set_text("Do you like Volgon poetry?");

    std::vector<hitchhiker::Question> questions;
    questions.push_back(q1);
    questions.push_back(q2);
    questions.push_back(q3);

    auto answers = magrathean.askQuestions(questions);
    for (const auto &answer : answers) {
        std::cout << answer.text() << std::endl;
    }

    return 0;
}

