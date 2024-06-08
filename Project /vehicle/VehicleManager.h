#ifndef VEHICLE_MANAGER_H
#define VEHICLE_MANAGER_H

#include <QObject>
#include <QList>
#include <QSharedPointer>
#include "Vehicle.h"

class VehicleManager : public QObject {
    Q_OBJECT

public:
    explicit VehicleManager(QObject *parent = nullptr);

    void addVehicle(QSharedPointer<Vehicle> vehicle);
    void editVehicle(int index, QSharedPointer<Vehicle> vehicle);
    void removeVehicle(int index);
    QList<QSharedPointer<Vehicle>> getVehicleList() const;

    void saveToFile(const QString &filename) const;
    void loadFromFile(const QString &filename);

private:
    QList<QSharedPointer<Vehicle>> vehicles;
};

#endif // VEHICLE_MANAGER_H
