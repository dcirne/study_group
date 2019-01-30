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

#include <future>
#include <iostream>
#include <string>

//
// Scoreboard
//
class Scoreboard final : public Subject {
    unsigned int _home;
    unsigned int _visitor;

public:
    Scoreboard() : Subject() {}

    void updateScore(const unsigned int home, const unsigned int visitor) noexcept {
        _home = home;
        _visitor = visitor;

        notify("Score");
    }

    unsigned int home() const noexcept {
        return _home;
    };

    unsigned int visitor() const noexcept {
        return _visitor;
    }
};


//
// SportsApp
//
class SportsApp final : public Observer {
    std::string _name;
    unsigned int _home;
    unsigned int _visitor;

    void displayScore() {
        std::cout << _name << " - Home team  " << _home << " vs " << _visitor << "  Visitor team" << std::endl;
    }

public:
    SportsApp(const std::string name) : Observer(), _name(name) {}

    friend void notificationHandler(Subject *subject, Observer *observer, std::string message);
};

void notificationHandler(Subject *subject, Observer *observer, std::string message) {
    if (subject == nullptr || observer == nullptr || message.compare("Score") != 0) {
        return;
    }

    auto scoreboard = static_cast<Scoreboard *>(subject);
    auto sportsApp = static_cast<SportsApp *>(observer);
    sportsApp->_home = scoreboard->home();
    sportsApp->_visitor = scoreboard->visitor();

    sportsApp->displayScore();
}

//
// main
//
int main(int argc, char *argv[]) {
    Scoreboard scoreboard;
    const std::string message("Score");

    SportsApp sa1("Android");
    SportsApp sa2("iOS");
    SportsApp sa3("IoT");
    SportsApp sa4("On-prem");

    auto t1 = std::async(std::launch::async, [&scoreboard, &sa1, &message]() {
        scoreboard.attach(&sa1, &notificationHandler, message);
    });
    auto t2 = std::async(std::launch::async, [&scoreboard, &sa2, &message]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        scoreboard.attach(&sa2, &notificationHandler, message);
    });
    auto t3 = std::async(std::launch::async, [&scoreboard, &sa3, &message]() {
        scoreboard.attach(&sa3, &notificationHandler, message);
    });

    t1.get();
    t2.get();
    t3.get();

    scoreboard.updateScore(1, 0);

    std::cout << "-------------------" << std::endl;

    scoreboard.detach(&sa2, message);
    scoreboard.attach(&sa4, &notificationHandler, message);
    scoreboard.updateScore(1, 1);
}
