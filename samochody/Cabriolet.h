//
// Created by Zosia Zakrzewska on 26/06/2022.
//

#ifndef DOMOWA5_CABRIOLET_H
#define DOMOWA5_CABRIOLET_H

#include <ostream>
#include "Car.h"


class Cabriolet : public Car {

private:
    bool isRoofOpen;

public:
    Cabriolet(double maxSpeed, double petrol, double fuelCon, bool isRoofOpen);
    void drive(double speed, double distance) override;
    void setIsRoofOpen(bool isRoofOpen);

    friend std::ostream &operator<<(std::ostream &os, const Cabriolet &cabriolet);
};


#endif //DOMOWA5_CABRIOLET_H
