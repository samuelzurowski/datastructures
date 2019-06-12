//
//  Car.hpp
//  P1-Reservation
//
//  Created by Samuel Zurowski on 3/18/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;
class InvalidTypeException{};
class Car {
private:
    string plateNumber;
    string make; // maker of vehicle
    string model;
    double pricePerDay;
    bool isAvailable = true;
    string enumToString() const;
    enum vehicleType {SEDAN, SUV, EXOTIC} type;
public:
    void setAvailable(bool available);
    string getPlate() const { return plateNumber; }
    bool isAvail() const { return isAvailable; }
    friend ostream& operator<<(ostream& os, const Car& c);
    Car(string maker, string vType, string model, string plate, double price);
    Car() = default;
};
