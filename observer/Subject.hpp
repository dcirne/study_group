#ifndef subject_hpp
#define subject_hpp

#include "Observer.hpp"

#include <list>
#include <mutex>
#include <string>

class Subject {
    struct Observation final {
        Observer *observer = nullptr;
        void (*callback)(Subject *, Observer *observer, const std::string) = nullptr;
        std::string message;

        bool operator==(const Observation &rhs) {
            return observer == rhs.observer && message.compare(rhs.message) == 0;
        }

        bool operator!=(const Observation &rhs) {
            return !(*this == rhs);
        }
    };

    std::list<Observation> _observationList;
    std::mutex _observersMutex;

protected:
    Subject() = default;

public:
    virtual ~Subject() = default;
    virtual void attach(Observer *observer, void (*callback)(Subject *, Observer *observer, const std::string), const std::string message) noexcept;
    virtual void detach(Observer *observer, const std::string message) noexcept;
    virtual void notify(const std::string message) noexcept;
};

#endif
