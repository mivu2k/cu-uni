#include "VehicleManager.h"
#include "Car.h"
#include "Truck.h"
#include <QFile>
#include <QTextStream>

VehicleManager::VehicleManager(QObject *parent) : QObject(parent) {}

void VehicleManager::addVehicle(QSharedPointer<Vehicle> vehicle) {
    vehicles.append(vehicle);
}

void VehicleManager::editVehicle(int index, QSharedPointer<Vehicle> vehicle) {
    if (index >= 0 && index < vehicles.size()) {
        vehicles[index] = vehicle;
    }
}

void VehicleManager::removeVehicle(int index) {
    if (index >= 0 && index < vehicles.size()) {
        vehicles.removeAt(index);
    }
}

QList<QSharedPointer<Vehicle>> VehicleManager::getVehicleList() const {
    return vehicles;
}

void VehicleManager::saveToFile(const QString &filename) const {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        for (const auto &vehicle : vehicles) {
            out << vehicle->getType() << ","
                << vehicle->getMake() << ","
                << vehicle->getModel() << ","
                << vehicle->getYear() << ","
                << vehicle->getVin();
            if (vehicle->getType() == "Car") {
                out << "," << dynamic_cast <Car*>(vehicle.data())->getNumDoors();
            } else if (vehicle->getType() == "Truck") {
                out << "," << dynamic_cast<Truck*>(vehicle.data())->getLoadCapacity();
            }
            out << "\n";
        }
    }
    file.close();
}

void VehicleManager::loadFromFile(const QString &filename) {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        vehicles.clear();
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() >= 5) {
                QString type = parts[0];
                QString make = parts[1];
                QString model = parts[2];
                int year = parts[3].toInt();
                QString vin = parts[4];

                QSharedPointer<Vehicle> vehicle;
                if (type == "Car" && parts.size() == 6) {
                    int numDoors = parts[5].toInt();
                    vehicle = QSharedPointer<Car>::create(make, model, year, vin, numDoors);
                } else if (type == "Truck" && parts.size() == 6) {
                    double loadCapacity = parts[5].toDouble();
                    vehicle = QSharedPointer<Truck>::create(make, model, year, vin, loadCapacity);
                }

                if (vehicle) {
                    vehicles.append(vehicle);
                }
            }
        }
    }
    file.close();
}
