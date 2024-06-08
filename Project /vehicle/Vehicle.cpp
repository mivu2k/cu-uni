#include "Vehicle.h"

Vehicle::Vehicle(const QString &make, const QString &model, int year, const QString &vin)
    : make(make), model(model), year(year), vin(vin) {}

QString Vehicle::getMake() const {
    return make;
}

QString Vehicle::getModel() const {
    return model;
}

int Vehicle::getYear() const {
    return year;
}

QString Vehicle::getVin() const {
    return vin;
}
