#include "Truck.h"

Truck::Truck(const QString &make, const QString &model, int year, const QString &vin, double loadCapacity)
    : Vehicle(make, model, year, vin), loadCapacity(loadCapacity) {}

double Truck::getLoadCapacity() const {
    return loadCapacity;
}

QString Truck::getType() const {
    return "Truck";
}
