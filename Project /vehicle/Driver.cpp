#include "Driver.h"

Driver::Driver(const QString &name, const QString &licenseNumber)
    : name(name), licenseNumber(licenseNumber) {}

QString Driver::getName() const {
    return name;
}

QString Driver::getLicenseNumber() const {
    return licenseNumber;
}
