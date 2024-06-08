#include "Car.h"

Car::Car(const QString &make, const QString &model, int year, const QString &vin, int numDoors)
    : Vehicle(make, model, year, vin), numDoors(numDoors) {}

int Car::getNumDoors() const {
    return numDoors;
}

QString Car::getType() const {
    return "Car";
}
