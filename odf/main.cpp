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

#include "foo_bar.pb.h"
#include "odf.pb.h"

#include <chrono>
#include <functional>
#include <iostream>
#include <map>
#include <string>

constexpr double SECOND_TO_NANO_MULTIPLIER = 1'000'000'000.0;

std::map<ODF::DataType, std::function<void(const ODF::Value &)>> dataTypeFunctionMap;

//
// Maps ODF Data Types to unpacking lambda functions
//
void mapUnpackingFunctions() {
    dataTypeFunctionMap[ODF::DataType::FOO] = [](const ODF::Value &value) {
        google::protobuf::Message *messagePtr = new Foo();
        value.value().UnpackTo(messagePtr);
        std::cout << "    Value song: " << ((Foo *)messagePtr)->song() << ", playhead: " << ((Foo *)messagePtr)->playhead() << std::endl;
    };

    dataTypeFunctionMap[ODF::DataType::BAR] = [](const ODF::Value &value) {
        Bar bar;
        value.value().UnpackTo(&bar);
        std::cout << "    Value type: " << static_cast<int>(bar.type()) << ", weight: " << bar.weight() << ", length: " << bar.length() << std::endl;
    };
}

//
// Converts chrono time_point to a time internal (double)
//
double timePointToTimeinterval(const std::chrono::time_point<std::chrono::system_clock> timePoint) {
    std::chrono::steady_clock::duration timeSinceEpoch = timePoint.time_since_epoch();
    std::chrono::seconds secs = std::chrono::duration_cast<std::chrono::seconds>(timeSinceEpoch);
    std::chrono::nanoseconds nanosecs = std::chrono::duration_cast<std::chrono::nanoseconds>(timeSinceEpoch - secs);
    return static_cast<double>(secs.count() + nanosecs.count() / SECOND_TO_NANO_MULTIPLIER);
}

//
// Adds an instance of a protobuf message to an Info Item
//
void addMessageToInfoItem(ODF::InfoItem *infoItem, const google::protobuf::Message *msg) {
    google::protobuf::Any *anyObject = new google::protobuf::Any();
    anyObject->PackFrom(*msg);

    ODF::Value *val = infoItem->add_values();
    auto timePoint = std::chrono::system_clock::now();
    val->set_date_time(timePointToTimeinterval(timePoint));
    val->set_allocated_value(anyObject);
}

//
// Populates an ODF Objects with several Info Items and Values
//
void populateObjects(ODF::Objects &objects) {
    // Foo object
    ODF::Object *fooObj = objects.add_objects();
    fooObj->set_id("foo123");
    fooObj->set_data_type(ODF::DataType::FOO);

    // Foo Info Items
    ODF::InfoItem *fooInfoItem = new ODF::InfoItem();
    fooInfoItem->set_name("Foo name");
    fooInfoItem->set_description("Description of Foo");
    fooObj->set_allocated_info_item(fooInfoItem);

    // Foo values
    Foo fighters;
    fighters.set_song("Times Like These");
    fighters.set_playhead(0.1);
    addMessageToInfoItem(fooInfoItem, &fighters);

    decltype(fighters) fighters2;
    fighters2.set_song("Times Like These");
    fighters2.set_playhead(0.3);
    addMessageToInfoItem(fooInfoItem, &fighters2);

    // Bar object
    ODF::Object *barObj = objects.add_objects();
    barObj->set_id("bar456");
    barObj->set_data_type(ODF::DataType::BAR);

    // Bar Info Items
    ODF::InfoItem *barInfoItem = new ODF::InfoItem();
    barInfoItem->set_name("Bar name");
    barInfoItem->set_description("Description of Bar");
    barObj->set_allocated_info_item(barInfoItem);

    // Bar values
    Bar *bell = new Bar();
    bell->set_type(Bar_Type_LONG);
    bell->set_weight(100);
    bell->set_length(42);
    addMessageToInfoItem(barInfoItem, bell);
}

//
// Prints an Object Data Type
//
void printObjectDataType(const ODF::Object &obj) {
    std::cout << "Object Data Type: ";

    switch (obj.data_type()) {
        case ODF::DataType::FOO:
            std::cout << "Foo";
            break;

        case ODF::DataType::BAR:
            std::cout << "Bar";
            break;

        default:
            std::cout << "Primitive";
            break;
    }

    std::cout << std::endl;
}

//
// Print an Info Item's Value
//
void printValue(const ODF::Value &value, const ODF::DataType dataType) {
    std::cout << "    Value date time: " << value.date_time() << std::endl;

    if (value.has_value()) {
        auto dataTypeFunctionMapIterator = dataTypeFunctionMap.find(dataType);
        if (dataTypeFunctionMapIterator != dataTypeFunctionMap.end()) {
            (dataTypeFunctionMapIterator->second)(value);
        } else {
            std::cout << "    Primitive value" << std::endl;
        }
    }
}

//
// Parses an ODF Objects
//
void parseObjects(const ODF::Objects &objects) {
    for (int i = 0; i < objects.objects_size(); ++i) {
        const ODF::Object &obj = objects.objects(i);
        std::cout << "Object Id: " << obj.id() << std::endl;
        printObjectDataType(obj);

        if (obj.has_info_item()) {
            const ODF::InfoItem &infoItem = obj.info_item();

            std::cout << "  Info item name: " << infoItem.name() << std::endl;
            std::cout << "  Info item description: " << infoItem.description() << std::endl;

            for (const auto &value : infoItem.values()) {
                printValue(value, obj.data_type());
            }
        }
    }
}

//
// main
//
int main(int argc, char *argv[]) {
    mapUnpackingFunctions();

    ODF::Objects objects;
    objects.set_version(1);
    populateObjects(objects);

    std::string serializedObjects;
    bool success = objects.SerializeToString(&serializedObjects);
    if (!success) {
        std::cerr << "Failed to serialize objects." << std::endl;
        return 1;
    }

    ODF::Objects deserializedObjects;
    success = deserializedObjects.ParseFromString(serializedObjects);
    if (!success) {
        std::cerr << "Failed to deserialize objects' serialized string." << std::endl;
        return 1;
    }

    parseObjects(deserializedObjects);

    return 0;
}
