#include "Subject.hpp"

void Subject::attach(Observer *observer, void (*callback)(Subject *, Observer *observer, std::string), const std::string message) noexcept {
    if (observer == nullptr || callback == nullptr || message.empty()) {
        return;
    }

    std::unique_lock<std::mutex> queueLock(_observersMutex);

    Observation observation;
    observation.observer = observer;
    observation.callback = callback;
    observation.message = message;
    _observationList.push_back(observation);
}

void Subject::detach(Observer *observer, const std::string message) noexcept {
    if (observer == nullptr || message.empty()) {
        return;
    }

    std::unique_lock<std::mutex> queueLock(_observersMutex);

    Observation observationToRemove;
    observationToRemove.observer = observer;
    observationToRemove.message = message;

    _observationList.remove_if([&observationToRemove](Observation &observation) {
        return observation == observationToRemove;
    });
}

void Subject::notify(const std::string message) noexcept {
    for (auto iterator = _observationList.cbegin(); iterator != _observationList.cend(); ++iterator) {
        const Observation *observation = &(*iterator);

        if (message.empty() || message.compare(observation->message) == 0) {
            observation->callback(this, observation->observer, message);
        }
    }
}
