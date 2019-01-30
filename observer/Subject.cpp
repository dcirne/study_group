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
