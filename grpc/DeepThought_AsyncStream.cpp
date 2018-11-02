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
        grpc::ServerAsyncReaderWriter<hitchhiker::Answer, hitchhiker::Question> _stream;

        enum class Status {
            Boot,
            Listening,
            Thinking,
            Done,
            Shutdown,
        };

        Status _status;
        Status _previousStatus;

        unsigned int count = 0;

      public:
        RequestHandler(hitchhiker::Computer::AsyncService *asyncService, grpc::ServerCompletionQueue *completionQueue)
            : _asyncService(asyncService), _completionQueue(completionQueue), _stream(&_context), _status(Status::Boot), _previousStatus(Status::Boot)
        {
            Think();
        }

        void Think() {
            std::cout << "count: " << count++ << std::endl;

            switch (_status) {
                case Status::Boot:
                    std::cout << "Status::Boot" << std::endl;
                    _status = Status::Listening;
                    _previousStatus = Status::Boot;
                    _asyncService->RequestInquires(&_context, &_stream, _completionQueue, _completionQueue, this);
                    break;

                case Status::Listening: {
                    std::cout << "Status::Listening" << std::endl;
                    _stream.Read(&_question, this);

                    if (_previousStatus == Status::Boot) {
                        new RequestHandler(_asyncService, _completionQueue);
                    }
                    _status = Status::Thinking;
                    _previousStatus = Status::Listening;
                }
                    break;

                case Status::Thinking: {
                    std::cout << "Status::Thinking" << std::endl;
                    hitchhiker::Answer answer;
                    std::string answerText;

                    std::cout << _question.text() << std::endl;
                    if (_question.text() == "What is answer to the ultimate question of life, the universe, and everything?") {
                        answerText = "The answer is: 42";
                        _status = Status::Listening;
                    } else if (_question.text() == "How many roads must a man walk down?") {
                        answerText = "At least one.";
                        _status = Status::Listening;
                    } else {
                        answerText = "Hmmm, let me think. Come back in a thousand years.";
                        _status = Status::Done;
                    }

                    answer.set_text(answerText);
                    _stream.Write(answer, this);
                    _previousStatus = Status::Thinking;
                }
                    break;

                case Status::Done:
                    std::cout << "Status::Done" << std::endl;
                    _stream.Finish(grpc::Status::OK, this);
                    _status = Status::Shutdown;
                    _previousStatus = Status::Done;
                    break;

                case Status::Shutdown:
                    _previousStatus = Status::Shutdown;
                    std::cout << "Status::Shutdown" << std::endl;
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
