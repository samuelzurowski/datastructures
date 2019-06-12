//
//  Car.cpp
//  P1-Reservation
//
//  Created by Samuel Zurowski on 3/18/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#include "Car.hpp"
// --------------------------------------------------------------------------
// Function: setAvailable
// Purpose: to change if the car is available.
void Car::setAvailable(bool available){
    isAvailable = available;
}
// --------------------------------------------------------------------------
// Function: enum to string
// Purpose: to get a string value of the ENUM.
string Car::enumToString() const {
    switch(type){
        case SEDAN:
            return "Sedan";
        case SUV:
            return "SUV";
        case EXOTIC:
            return "Exotic";
        default:
            break;
    }
    return "";
}
// --------------------------------------------------------------------------
// Overloaded: <<
// Purpose: to format data in main nicely.
ostream& operator<<(ostream& os, const Car& c){
    os << left << setw(15) << c.make << setw(10) <<  c.model << ' '
    << setw(12) << c.enumToString() << '$' << setw(13)
    << c.pricePerDay << c.plateNumber;
    return os;
}

// --------------------------------------------------------------------------
// Function: Constructor for the Car
// Params: String maker, the type vehicle, the model, plate, and cost
Car::Car(string maker, string vType, string model, string plate, double price):
    make(maker), plateNumber(plate), model(model), pricePerDay(price) {
    if(vType == "sedan")
        type = vehicleType::SEDAN;
    else if(vType == "suv")
        type = vehicleType::SUV;
    else if(vType == "exotic")
        type = vehicleType::EXOTIC;
    else
        throw InvalidTypeException();
}
