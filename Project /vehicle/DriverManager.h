#ifndef DRIVER_MANAGER_H
#define DRIVER_MANAGER_H

#include <QObject>
#include <QList>
#include <QSharedPointer>
#include "Driver.h"

class DriverManager : public QObject {
    Q_OBJECT

public:
    explicit DriverManager(QObject *parent = nullptr);

    void addDriver(QSharedPointer<Driver> driver);
    void editDriver(int index, QSharedPointer<Driver> driver);
    void removeDriver(int index);
    QList<QSharedPointer<Driver>> getDriverList() const;

    void saveToFile(const QString &filename) const;
    void loadFromFile(const QString &filename);

private:
    QList<QSharedPointer<Driver>> drivers;
};

#endif // DRIVER_MANAGER_H
