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

#include "Drone.cpp"

#include <iostream>
#include <string>

//
// Factory
//
class DroneFactory {
public:
    DroneFactory() = default;
    virtual ~DroneFactory() = default;

    virtual Drone makeDrone() noexcept {
        return Drone();
    }

    virtual Blade makeBlade() noexcept {
        return Blade();
    }

    virtual Battery makeBattery(double capacity = 0) noexcept {
        Battery battery;
        if (capacity > 0) {
            battery.capacity = capacity;
        }
        return battery;
    }
};

Drone CreateDrone(DroneFactory &droneFactory) {
    Drone drone = droneFactory.makeDrone();

    for (auto i = 0; i < 6; ++i) {
        Blade blade = droneFactory.makeBlade();
        drone.blades.push_back(blade);
    }

    drone.battery = droneFactory.makeBattery(1.21);

    return drone;
}

//
// Builder
//
class DroneBuilder {
    Drone _drone;

public:
    DroneBuilder() {
        _drone.color = Color::VeryDarkGrey;
    };

    DroneBuilder *addBlade() noexcept {
        Blade blade;
        _drone.blades.push_back(blade);
        return this;
    }

    DroneBuilder *addBattery(double capacity = 0) noexcept {
        Battery battery;
        if (capacity > 0) {
            battery.capacity = capacity;
        }
        _drone.battery = battery;
        return this;
    }

    Drone build() {
        _drone.wingSpan = 42;
        return _drone;
    }
};

Drone BuildDrone(DroneBuilder &droneBuilder) {
    Drone drone = droneBuilder
                  .addBlade()
                  ->addBlade()
                  ->addBlade()
                  ->addBlade()
                  ->addBattery(2.71)
                  ->build();
    return drone;
}

//
// main
//
int main(int argc, char *argv[]) {
    DroneFactory droneFactory;
    Drone drone1 = CreateDrone(droneFactory);
    drone1.printDescription();

    DroneBuilder droneBuilder;
    Drone drone2 = BuildDrone(droneBuilder);
    drone2.printDescription();

    return 0;
}
