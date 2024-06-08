#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
public:
    Truck(const QString &make, const QString &model, int year, const QString &vin, double loadCapacity);

    double getLoadCapacity() const;
    QString getType() const override;

private:
    double loadCapacity;
};

#endif // TRUCK_H
