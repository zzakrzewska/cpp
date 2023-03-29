//
// Created by Zosia Zakrzewska on 26/06/2022.
//

#include "Cabriolet.h"

Cabriolet::Cabriolet(double maxSpeed, double petrol, double fuelCon, bool isRoofOpen) : Car(maxSpeed, petrol, fuelCon),
                                                                                        isRoofOpen(isRoofOpen) {}

void Cabriolet::setIsRoofOpen(bool isRoofOpen) {
    Cabriolet::isRoofOpen = isRoofOpen;
}

void Cabriolet::drive(double speed, double distance) {
    if(isRoofOpen) {
        speed -= speed * 0.1;
        std::cout << "Dach w samochodzie otwarty - predkosc zmniejszona o 10%" << std::endl;
    } else
        std::cout << "Dach w samochodzie zamkniety" << std::endl;

    Car::drive(speed, distance);
}

std::ostream &operator<<(std::ostream &os, const Cabriolet &cabriolet) {
    os << static_cast<const Car &>(cabriolet);

    if(cabriolet.isRoofOpen)
        std::cout << "Dach jest otwarty." << std::endl;
    else
        std::cout << "Dach jest zamkniety." << std::endl;

    return os;
}
