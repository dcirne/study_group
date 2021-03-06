// Copyright 2019 Dalmo Cirne
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "hitchhiker.pb.h"
#include "hitchhiker.grpc.pb.h"

#include <grpcpp/grpcpp.h>
#include <iostream>
#include <memory>
#include <string>

class DeepThought final : public hitchhiker::Computer::Service {
  public:
    grpc::Status Inquire(grpc::ServerContext *context, const hitchhiker::Question *question, hitchhiker::Answer *answer) override {
        std::cout << question->text() << std::endl;
        answer->set_text("42");
        return grpc::Status::OK;
    }

    grpc::Status Inquires(grpc::ServerContext *context, grpc::ServerReaderWriter<hitchhiker::Answer, hitchhiker::Question> *stream) override {
        hitchhiker::Question question;
        while (stream->Read(&question)) {
            hitchhiker::Answer answer;
            std::string answerText;

            std::cout << question.text() << std::endl;

            if (question.text() == "What is answer to the ultimate question of life, the universe, and everything?") {
                answerText = "The answer is: 42";
            } else if (question.text() == "How many roads must a man walk down?") {
                answerText = "At least one.";
            } else {
                answerText = "Hmmm, let me think. Come back in a thousand years.";
            }

            answer.set_text(answerText);
            stream->Write(answer);
        }
        return grpc::Status::OK;
    }
};

void runDeepThought(const std::string ip, const std::string port) {
    std::string serverAddress = ip + ":" + port;
    DeepThought deepThought;

    grpc::ServerBuilder serverBuilder;
    serverBuilder.AddListeningPort(serverAddress, grpc::InsecureServerCredentials());
    serverBuilder.RegisterService(&deepThought);

    std::unique_ptr<grpc::Server> server(serverBuilder.BuildAndStart());
    std::cout << "Greetings, I am Deep Thought." << std::endl;
    server->Wait();
}

int main(int argc, char **argv) {
    runDeepThought("0.0.0.0", "4242");

    return 0;
}
