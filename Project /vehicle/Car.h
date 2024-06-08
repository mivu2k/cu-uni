#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(const QString &make, const QString &model, int year, const QString &vin, int numDoors);

    int getNumDoors() const;
    QString getType() const override;

private:
    int numDoors;
};

#endif // CAR_H
