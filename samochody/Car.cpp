//
// Created by Zosia Zakrzewska on 26/06/2022.
//

#include "Car.h"

Car::Car(double maxSpeed, double petrol, double fuelCon) {
    Car::maxSpeed = maxSpeed;
    Car::petrol = petrol;
    Car::fuelCon = fuelCon;
}

void Car::drive(double speed, double distance){
    double fuel;
    bool max = true;

    if(speed > Car::maxSpeed) {
        std::cout << "Predkosc wieksza niz maksymalna predkosc pojazdu" << std::endl;
        max = false;
    }

    if(speed > 0.8*Car::maxSpeed || speed < 0.3*Car::maxSpeed) {
        fuel = Car::fuelCon + Car::fuelCon*0.2;
    } else {
        fuel = Car::fuelCon;
    }

    double fuelUsed = distance/100*fuel;

    if(fuelUsed <= Car::petrol && max)
        std::cout << "Samochod przejechal caly dystans " << distance << " km, spalil "
            << fuelUsed << " litrow benzyny" << std::endl;
    else if(max) {
        double distanceCovered = Car::petrol/fuel*100;
        std::cout << "Samochod przejechal " << distanceCovered << " km z " << distance << ", spalil "
            << Car::petrol << " litrow benzyny. Aby przejechac caly dystans potrzebowal " << fuelUsed
            << " litrow benzyny." << std::endl;
    }

}

void Car::addPetrol(double petrol) {
    Car::petrol += petrol;
}

std::ostream &operator<<(std::ostream &os, const Car &car) {
    std::cout << "Samochod moze jechac z maksymalna predkoscia " << car.maxSpeed << " km/h, ";
    std::cout << "srednio spala " << car.fuelCon << " litrow benzyny na 100 km." << std::endl;
    std::cout << "Obecnie w baku ma " << car.petrol << " litrow benzyny." << std::endl;
    return os;
}
