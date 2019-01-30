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
#include <future>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <tuple>

class Magrathean final {
    std::unique_ptr<hitchhiker::Computer::Stub> _computerStub;
    int _uniqueRequestId;

  public:
    Magrathean(std::shared_ptr<grpc::Channel> channel, const int uniqueRequestId = 42)
    : _computerStub(hitchhiker::Computer::NewStub(channel)), _uniqueRequestId(uniqueRequestId)
    {
    }

    std::tuple<std::string, int> askQuestion(const std::string questionText) {
        grpc::ClientContext clientContext;
        grpc::CompletionQueue completionQueue;
        grpc::Status status;

        hitchhiker::Question question;
        question.set_text(questionText);
        hitchhiker::Answer answer;

        std::unique_ptr<grpc::ClientAsyncResponseReader<hitchhiker::Answer>> answerRPC(_computerStub->PrepareAsyncInquire(&clientContext, question, &completionQueue));
        answerRPC->StartCall();
        answerRPC->Finish(&answer, &status, (void *)&_uniqueRequestId);

        void *receivedUniqueRequestId;
        bool success = false;
        completionQueue.Next(&receivedUniqueRequestId, &success);

        if (*((int *)receivedUniqueRequestId) != _uniqueRequestId) {
            std::cout << "Received response from a different request." << std::endl;
        }

        if (status.ok()) {
            return std::make_tuple(answer.text(), _uniqueRequestId);
        } else {
            std::cout << "gRPC error. Code: " << status.error_code() << ", message: " << status.error_message() << std::endl;
            return std::make_tuple("Deep Thought is not available.", _uniqueRequestId);
        }
    }
};

int main(int argc, char **argv) {
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:4242", grpc::InsecureChannelCredentials());

    auto t1 = std::async(std::launch::async, [&channel]() {
        const auto uniqueRequestId = 1;
        Magrathean magrathean(channel, uniqueRequestId);
        auto theAnswer = magrathean.askQuestion("What is answer to the ultimate question of life, the universe, and everything?");
        std::cout << "Unique request id: " << std::get<1>(theAnswer) << " – " << std::get<0>(theAnswer) << std::endl;
    });

    auto t2 = std::async(std::launch::async, [&channel]() {
        const auto uniqueRequestId = 2;
        Magrathean magrathean(channel, uniqueRequestId);
        auto theAnswer = magrathean.askQuestion("How many roads must a man walk down?");
        std::cout << "Unique request id: " << std::get<1>(theAnswer) << ", " << std::get<0>(theAnswer) << std::endl;
    });

    t1.get();
    t2.get();

    return 0;
}

