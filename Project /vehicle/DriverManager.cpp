#include "DriverManager.h"
#include <QFile>
#include <QTextStream>

DriverManager::DriverManager(QObject *parent) : QObject(parent) {}

void DriverManager::addDriver(QSharedPointer<Driver> driver) {
    drivers.append(driver);
}

void DriverManager::editDriver(int index, QSharedPointer<Driver> driver) {
    if (index >= 0 && index < drivers.size()) {
        drivers[index] = driver;
    }
}

void DriverManager::removeDriver(int index) {
    if (index >= 0 && index < drivers.size()) {
        drivers.removeAt(index);
    }
}

QList<QSharedPointer<Driver>> DriverManager::getDriverList() const {
    return drivers;
}

void DriverManager::saveToFile(const QString &filename) const {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        for (const auto &driver : drivers) {
            out << driver->getName() << ","
                << driver->getLicenseNumber() << "\n";
        }
    }
    file.close();
}

void DriverManager::loadFromFile(const QString &filename) {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        drivers.clear();
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() == 2) {
                QString name = parts[0];
                QString licenseNumber = parts[1];
                QSharedPointer<Driver> driver = QSharedPointer<Driver>::create(name, licenseNumber);
                drivers.append(driver);
            }
        }
    }
    file.close();
}
