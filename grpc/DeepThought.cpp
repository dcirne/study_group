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
