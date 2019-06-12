//
//  main.cpp
//  P1-Reservation
//
//  Created by Samuel Zurowski on 3/18/19.
//  Copyright © 2019 Samuel Zurowski. All rights reserved.
//

#define ERR_MSG "Invalid Value, Try Again." // used for error message.

#include "List.hpp"
#include "Car.hpp"
#include "tools.hpp"
#include "Reservation.hpp"

using namespace std;
// ---------------------------------------------------------
// All Prototypes
void prompt(const vector<string> options);
void listCars(const List<Car> &c, bool showAll);
void addCar(List<Car> &c);
void listReservedVehicles(List<Reservation> &r, List<Car> &c);
void removeCar(List<Car> &c);
void cancelReservation(List<Reservation> &r, List<Car> &c);
void chooseOption(List<Reservation> &r, List<Car> &c, const vector<string> &o);
void addReservation(List<Reservation> &r, List<Car> &c);
// ---------------------------------------------------------

int main(int argc, const char * argv[]) {
    const vector<string> options { // options for the car place
        "List all cars", "Add Car to Inventory", "Remove car from Inventory",
        "List all reservations", "Add a reservation", "Cancel Reservation",
        "Exit"
    };
    auto car = List<Car>(); // list of cars
    auto reserved = List<Reservation>(); // list of reserved cars
    
    chooseOption(reserved, car, options);
    return 0;
}

// ----------------------------------------------------------------------------
// Function: chooseOption 
// Desc    : Allows the user to choose an option for the car rental
// ----------------------------------------------------------------------------
void chooseOption(List<Reservation> &r, List<Car> &c, const vector<string> &o) {
    char choice;
    for(;;) {
        prompt(o); // list menu
        menuChoice(choice, "Please Enter a Value: "); // chose value.
        switch (choice) {
            case '1': // List cars
                listCars(c, 1);
                break;
            case '2':
                addCar(c);
                break;
            case '3': // Remove a car
                removeCar(c);
                break;
            case '4': // Listing Reserved Vehicles
                listReservedVehicles(r, c);
                break;
            case '5': // Adding a Reservation
                addReservation(r, c);
                break;
            case '6': // Cancel a Reservation.
                cancelReservation(r, c);
                break;
            case '7': // Abort the Program.
                cout << "Thank you for using XYZ Car Rental, aborting." << endl;
                exit(0);
            default:
                cout << ERR_MSG << endl;
                break;
        }
    }
}

// ----------------------------------------------------------------------------
// Function: template checkAmt
// Desc    : Allows to check how many slots are being used in a list.
// return  : boolean
// ----------------------------------------------------------------------------
template <typename T>
bool checkAmt(const List<T> &type) {
    if(type.getSlots() == 0) {
        cout << "There are no vehicles available." << endl;
        return false;
    } return true;
}

// ----------------------------------------------------------------------------
// Function: add a Reservation
// Desc    : Allows to add a reservation of any of the cars.
// ----------------------------------------------------------------------------
void addReservation(List<Reservation> &r, List<Car> &c) {
    if(checkAmt(c) == 0) return;
    
    int var = 0;
    while(var <= 0 || var > c.getSlots()) {
        listCars(c, 0);
        cout << c.getSlots() + 1 << ". Exit" << endl;
        inputInteger(var, "Select Car to Reserve: ", ERR_MSG);
        
        if(var == 0) continue; // to avoid - 1 in check
        if(var == c.getSlots() + 1) return;
        
        if(!c[var - 1].isAvail()) {
            cerr << "Car is currently Reserved" << endl;
            var = 0;
        }
    } string s;
    
    inputString(s, "Enter your name: ");
    r.add(Reservation(s, c[var - 1].getPlate())); // create the resevation
    c[var - 1].setAvailable(0); // set the car to not available.
}

// ----------------------------------------------------------------------------
// Function: list reserved vehicles
// Desc    : be able to see a list of the vehicles that are reserved.
// ----------------------------------------------------------------------------
void listReservedVehicles(List<Reservation> &r, List<Car> &c) {
    if(checkAmt(r) == 0) return;
    
    reservedHeader();
    
    for(int i = 0; i < r.getSlots(); i++) // n^2 time
        for(int j = 0; j < c.getSlots(); j++)
            if(r[i].getPlate() == c[j].getPlate())
                cout << i+1 << ". " << r[i] << c[j] << endl;
}

// ----------------------------------------------------------------------------
// Function: Cancel a reservation
// Desc    : cancel a car that is currently reserved
// ----------------------------------------------------------------------------
void cancelReservation(List<Reservation> &r, List<Car> &c) {
    if(checkAmt(r) == 0) return;
    
    string var;
    int loc = 0;
    for(;;) {
        inputString(var, "Enter Name of Reservation (q to quit): ");
        if(var == "q") return;
        
        for(int i = 0; i < r. getSlots(); i++)
            if(r[i].getName() == var) {
                loc = i;
                break;
            }
        if(r[loc].getName() == var) break;
    }
    
    for(int i = 0; i < c.getSlots(); i++)
        if(r[loc].getPlate() == c[i].getPlate()) {
            cout << r[loc].getName() << " is no longer reserving a car" << endl;
            c[i].setAvailable(1);
            r.erase(loc);
            break;
        }
}

// ----------------------------------------------------------------------------
// Function: list all cars
// Desc    : show all the cars in inventory
// ----------------------------------------------------------------------------
void listCars(const List<Car> &c, bool showAll) {
    if(checkAmt(c) == 0) return;
    listHeader();
    if(showAll == 1)
        for(int i = 0; i < c.getSlots(); i++)
            cout << i+1 << ". " <<  c[i] << endl;
    else
        for(int i = 0; i < c.getSlots(); i++) {
            if(c[i].isAvail())
                cout << i+1 << ". " <<  c[i] << endl;
        }
}

// ----------------------------------------------------------------------------
// Function: remove a car from inventory
// Desc    : remove a car that is NOT reserved
// ----------------------------------------------------------------------------
void removeCar(List<Car> &c) {
    if(checkAmt(c) == 0) return;
    int var = 0;
    while(var <= 0 || var > c.getSlots()) {
        listCars(c, 1);
        cout << c.getSlots() + 1 << ". Exit" << endl;
        inputInteger(var, "Enter Car to Remove: ", ERR_MSG);
        
        if(var == 0) continue;
        if(var == c.getSlots() + 1) return;
        
        if(!c[var - 1].isAvail()) {
            cerr << "\nCar is currently reserved\n" << endl;
            var = 0;
        }
    } c.erase(var - 1); // erase the car
}

// ----------------------------------------------------------------------------
// Function: Car Rental Header
// Desc    : header for the menu
// ----------------------------------------------------------------------------
void header() {
    cout << string(43, '-') << endl << "XYZ Car Rental" << endl;
    cout << string(43, '-') << endl;
}

// ----------------------------------------------------------------------------
// Function: prompt
// Desc    : list all the choices in the menu
// ----------------------------------------------------------------------------
void prompt(const vector<string> options) {
    int i = 1;
    header();
    for(auto val: options)
        cout << i++ << ". " << val << endl;
}

// ----------------------------------------------------------------------------
// Function: typeVehicle
// Desc    : to choose sedan, suv, or exotic car type.
// ----------------------------------------------------------------------------
void typeVehicle(string& var) {
    while(var != "sedan" && var != "suv" && var != "exotic") {
        cout << "Enter type [sedan/suv/exotic]: ";
        cin >> ws;
        getline(cin, var);
        cin.clear();
    } cin.clear();
}

// ----------------------------------------------------------------------------
// Function: addCar
// Desc    : add a car to the XYZ Car Rental inventory.
// ----------------------------------------------------------------------------
void addCar(List<Car> &c) {
    string maker, type, model, plate;
    double price;
    
    inputDouble(price, "Enter Price Per Day: ", ERR_MSG);
    inputString(maker, "Enter the Maker: ");
    inputString(model, "Enter the Model: ");
    inputString(plate, "Enter the Plate: ");
    typeVehicle(type);
    c.add(Car(maker, type, model, plate, price));
}
