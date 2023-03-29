#include <iostream>
#include "Car.h"
#include "Cabriolet.h"

int main() {

    Car car = {250, 20, 8};
    std::cout << car;
    car.drive(220, 220);

    Cabriolet cabriolet = {200, 15, 10, true};
    std::cout << cabriolet;
    cabriolet.drive(150, 220);

    return 0;

}
