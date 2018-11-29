#ifndef subject_hpp
#define subject_hpp

#include "Observer.hpp"

#include <list>
#include <mutex>

class Subject {
    std::list<Observer *> _observers;
    std::mutex _observersMutex;

protected:
    Subject() = default;

public:
    virtual ~Subject() = default;
    virtual void attach(Observer *observer) noexcept;
    virtual void detach(Observer *observer) noexcept;
    virtual void notify() noexcept;
};

#endif
