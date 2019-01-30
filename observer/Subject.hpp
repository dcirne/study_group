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
