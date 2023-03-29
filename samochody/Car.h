//
// Created by Zosia Zakrzewska on 26/06/2022.
//

#ifndef DOMOWA5_CAR_H
#define DOMOWA5_CAR_H


#include <iostream>

class Car {

private:
    double maxSpeed;
    double petrol;
    double fuelCon;

public:
    Car(double maxSpeed, double petrol, double fuelCon);

    virtual void drive(double speed, double distance);
    void addPetrol(double petrol);
    friend std::ostream &operator<<(std::ostream &os, const Car &car);

};


#endif //DOMOWA5_CAR_H
