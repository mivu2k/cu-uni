#ifndef DRIVER_H
#define DRIVER_H

#include <QString>

class Driver {
public:
    Driver(const QString &name, const QString &licenseNumber);

    QString getName() const;
    QString getLicenseNumber() const;

private:
    QString name;
    QString licenseNumber;
};

#endif // DRIVER_H
