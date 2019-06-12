//
//  Reservation.hpp
//  P1-Reservation
//
//  Created by Samuel Zurowski on 3/19/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//
#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Reservation {
private:
    string name;
    string vehicleRented;
public:
    Reservation(string name, string vehicleRented);
    string getPlate() const { return vehicleRented; }
    string getName() const {return name; }
    Reservation() = default;
    friend ostream& operator<<(ostream& os, const Reservation& r);
};
