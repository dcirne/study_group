#include "hitchhiker.pb.h"
#include "hitchhiker.grpc.pb.h"

#include <chrono>
#include <grpcpp/grpcpp.h>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

class DeepThought final {
    std::unique_ptr<grpc::ServerCompletionQueue> _completionQueue;
    hitchhiker::Computer::AsyncService _asyncService;
    std::unique_ptr<grpc::Server> _server;

    void asyncHandler() {
        new RequestHandler(&_asyncService, _completionQueue.get());
        void *uniqueRequestPtr;
        bool success;

        while (true) {
            _completionQueue->Next(&uniqueRequestPtr, &success);

            if (success) {
                auto requestHandler = static_cast<RequestHandler *>(uniqueRequestPtr);
                requestHandler->Think();
            }
        }
    }

    // Inner class to serve a request
    class RequestHandler {
        hitchhiker::Computer::AsyncService *_asyncService;
        hitchhiker::Question _question;
        hitchhiker::Answer _answer;

        grpc::ServerCompletionQueue *_completionQueue;
        grpc::ServerContext _context;
        grpc::ServerAsyncResponseWriter<hitchhiker::Answer> _asyncResponseWriter;

        enum class Status {
            Boot,
            Thinking,
            Shutdown,
        } _status;

      public:
        RequestHandler(hitchhiker::Computer::AsyncService *asyncService, grpc::ServerCompletionQueue *completionQueue)
            : _asyncService(asyncService), _completionQueue(completionQueue), _asyncResponseWriter(&_context), _status(Status::Boot)
        {
            Think();
        }

        void Think() {
            switch (_status) {
                case Status::Boot:
                    _status = Status::Thinking;
                    _asyncService->RequestInquire(&_context, &_question, &_asyncResponseWriter, _completionQueue, _completionQueue, this);
                    break;

                case Status::Thinking: {
                    new RequestHandler(_asyncService, _completionQueue);
                    std::string answerText;

                    std::cout << _question.text() << std::endl;

                    if (_question.text() == "What is answer to the ultimate question of life, the universe, and everything?") {
                        answerText = "The answer is: 42";
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                    } else if (_question.text() == "How many roads must a man walk down?") {
                        answerText = "At least one.";
                    }

                    _answer.set_text(answerText);
                    _status = Status::Shutdown;
                    _asyncResponseWriter.Finish(_answer, grpc::Status::OK, this);
                }
                    break;

                case Status::Shutdown:
                    delete this;
                    break;
            }
        }
    }; // RequestHandler

  public:
    ~DeepThought() {
        _server->Shutdown();
        _completionQueue->Shutdown(); // Always shutdown the completion queue after the server
    }

    void run(const std::string ip, const std::string port) {
        std::string serverAddress = ip + ":" + port;

        grpc::ServerBuilder serverBuilder;
        serverBuilder.AddListeningPort(serverAddress, grpc::InsecureServerCredentials());
        serverBuilder.RegisterService(&_asyncService);

        _completionQueue = serverBuilder.AddCompletionQueue();
        _server = serverBuilder.BuildAndStart();

        std::cout << "Greetings, I am Deep Thought." << std::endl;

        asyncHandler();
    }
};

int main(int argc, char **argv) {
    DeepThought deepThought;
    deepThought.run("0.0.0.0", "4242");

    return 0;
}
