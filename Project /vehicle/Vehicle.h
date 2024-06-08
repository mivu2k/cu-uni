#ifndef VEHICLE_H
#define VEHICLE_H

#include <QString>

class Vehicle {
public:
    Vehicle(const QString &make, const QString &model, int year, const QString &vin);
    virtual ~Vehicle() {}

    QString getMake() const;
    QString getModel() const;
    int getYear() const;
    QString getVin() const;
    virtual QString getType() const = 0;

private:
    QString make;
    QString model;
    int year;
    QString vin;
};

#endif // VEHICLE_H
