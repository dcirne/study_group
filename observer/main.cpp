#include "Observer.hpp"
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

        notify();
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

    void update(Subject *subject) override {
        auto scoreboard = static_cast<Scoreboard *>(subject);
        _home = scoreboard->home();
        _visitor = scoreboard->visitor();

        displayScore();
    }
};


//
// main
//
int main(int argc, char *argv[]) {
    Scoreboard scoreboard;

    SportsApp sa1("Android");
    SportsApp sa2("iOS");
    SportsApp sa3("IoT");
    SportsApp sa4("On-prem");

    auto t1 = std::async(std::launch::async, [&scoreboard, &sa1]() {
        scoreboard.attach(&sa1);
    });
    auto t2 = std::async(std::launch::async, [&scoreboard, &sa2]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        scoreboard.attach(&sa2);
    });
    auto t3 = std::async(std::launch::async, [&scoreboard, &sa3]() {
        scoreboard.attach(&sa3);
    });

    t1.get();
    t2.get();
    t3.get();

    scoreboard.updateScore(1, 0);

    std::cout << "-------------------" << std::endl;

    scoreboard.detach(&sa2);
    scoreboard.attach(&sa4);
    scoreboard.updateScore(1, 1);
}
