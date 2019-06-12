//
//  Reservation.cpp
//  P1-Reservation
//
//  Created by Samuel Zurowski on 3/19/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#include "Reservation.hpp"
// --------------------------------------------------------------------------
// Function: Reservation constructor
// Params: Name of reserver, and license plate of vehicle rented.
Reservation::Reservation(string name, string vehicleRented)
:name(name), vehicleRented(vehicleRented) {}

// --------------------------------------------------------------------------
// Overloaded: <<
// Purpose: formatting of ostream
ostream& operator<<(ostream& os, const Reservation& r) {
    return os << right << setw(5)<< r.name << "\t\t";
}
