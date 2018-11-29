#include "Subject.hpp"

void Subject::attach(Observer *observer) noexcept {
    if (observer == nullptr) {
        return;
    }

    std::unique_lock<std::mutex> queueLock(_observersMutex);
    _observers.push_back(observer);
}

void Subject::detach(Observer *observer) noexcept {
    if (observer == nullptr) {
        return;
    }

    std::unique_lock<std::mutex> queueLock(_observersMutex);
    _observers.remove(observer);
}

void Subject::notify() noexcept {
    for (auto iterator = _observers.cbegin(); iterator != _observers.cend(); ++iterator) {
        (*iterator)->update(this);
    }
}
