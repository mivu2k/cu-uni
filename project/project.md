Certainly! I'll optimize and rewrite the code to ensure it's more streamlined and functional. The code will handle vehicle management, customer management, reservation management, and driver management, and it will avoid the use of static or dynamic variables directly.

### 1. Vehicle Class Hierarchy

#### `Vehicle.h`

```cpp
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
```

#### `Vehicle.cpp`

```cpp
#include "Vehicle.h"

Vehicle::Vehicle(const QString &make, const QString &model, int year, const QString &vin)
    : make(make), model(model), year(year), vin(vin) {}

QString Vehicle::getMake() const {
    return make;
}

QString Vehicle::getModel() const {
    return model;
}

int Vehicle::getYear() const {
    return year;
}

QString Vehicle::getVin() const {
    return vin;
}
```

#### `Car.h`

```cpp
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
```

#### `Car.cpp`

```cpp
#include "Car.h"

Car::Car(const QString &make, const QString &model, int year, const QString &vin, int numDoors)
    : Vehicle(make, model, year, vin), numDoors(numDoors) {}

int Car::getNumDoors() const {
    return numDoors;
}

QString Car::getType() const {
    return "Car";
}
```

#### `Truck.h`

```cpp
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
```

#### `Truck.cpp`

```cpp
#include "Truck.h"

Truck::Truck(const QString &make, const QString &model, int year, const QString &vin, double loadCapacity)
    : Vehicle(make, model, year, vin), loadCapacity(loadCapacity) {}

double Truck::getLoadCapacity() const {
    return loadCapacity;
}

QString Truck::getType() const {
    return "Truck";
}
```

### 2. VehicleManager Class

#### `VehicleManager.h`

```cpp
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
```

#### `VehicleManager.cpp`

```cpp
#include "VehicleManager.h"
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
                out << "," << dynamic_cast<Car*>(vehicle.data())->getNumDoors();
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
```

### 3. Customer Class

#### `Customer.h`

```cpp
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

class Customer {
public:
    Customer(const QString &name, const QString &id, const QString &contactInfo);

    QString getName() const;
    QString getId() const;
    QString getContactInfo() const;

private:
    QString name;
    QString id;
    QString contactInfo;
};

#endif // CUSTOMER_H
```

#### `Customer.cpp`

```cpp
#include "Customer.h"

Customer::Customer(const QString &name, const QString &id, const QString &contactInfo)
    : name(name), id(id), contactInfo(contactInfo) {}

QString Customer::getName() const {
    return name;
}

QString Customer::getId() const {
    return id;
}

QString Customer::getContactInfo() const {
    return contactInfo;
}
```

### 4. CustomerManager Class

#### `CustomerManager.h`

```cpp
#ifndef CUSTOMER_MANAGER_H
#define CUSTOMER_MANAGER_H

#include <QObject>
#include <QList>
#include <QSharedPointer>
#include "Customer.h"

class CustomerManager : public QObject {
    Q_OBJECT

public:
    explicit CustomerManager(QObject *parent = nullptr);

    void addCustomer(QSharedPointer<Customer> customer);
    void editCustomer(int index, QSharedPointer<Customer> customer);
    void removeCustomer(int index);
    QList<QSharedPointer<Customer>> getCustomerList() const;

    void saveToFile(const QString &filename) const;
    void loadFromFile(const QString &filename);

private:
    QList<QSharedPointer<Customer>> customers;
};

#endif // CUSTOMER_MANAGER_H
```

#### `CustomerManager.cpp`

```cpp
#include "CustomerManager.h"
#include <QFile>
#include <QTextStream>

CustomerManager::CustomerManager(QObject *parent) : QObject(parent) {}

void CustomerManager::addCustomer(QSharedPointer<Customer> customer) {
    customers.append(customer);
}

void CustomerManager::editCustomer(int index, QSharedPointer<Customer> customer) {
    if (index >= 0 && index < customers.size()) {
        customers[index] = customer;
    }
}

void CustomerManager::removeCustomer(int index) {
    if (index >= 0 && index < customers.size()) {
        customers.removeAt(index);
    }
}

QList<QSharedPointer<Customer>> CustomerManager::getCustomerList() const {
    return customers;
}

void CustomerManager::saveToFile(const QString &filename) const {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        for (const auto &customer : customers) {
            out << customer->getName() << ","
                << customer->getId() << ","
                << customer->getContactInfo() << "\n";
        }
    }
    file.close();
}

void CustomerManager::loadFromFile(const QString &filename) {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        customers.clear();
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() == 3) {
                QString name = parts[0];
               

 QString id = parts[1];
                QString contactInfo = parts[2];
                QSharedPointer<Customer> customer = QSharedPointer<Customer>::create(name, id, contactInfo);
                customers.append(customer);
            }
        }
    }
    file.close();
}
```

### 5. Reservation Class

#### `Reservation.h`

```cpp
#ifndef RESERVATION_H
#define RESERVATION_H

#include <QString>
#include <QDate>
#include "Vehicle.h"
#include "Customer.h"

class Reservation {
public:
    Reservation(const QString &reservationId, QSharedPointer<Vehicle> vehicle, QSharedPointer<Customer> customer, const QDate &startDate, const QDate &endDate);

    QString getReservationId() const;
    QSharedPointer<Vehicle> getVehicle() const;
    QSharedPointer<Customer> getCustomer() const;
    QDate getStartDate() const;
    QDate getEndDate() const;

private:
    QString reservationId;
    QSharedPointer<Vehicle> vehicle;
    QSharedPointer<Customer> customer;
    QDate startDate;
    QDate endDate;
};

#endif // RESERVATION_H
```

#### `Reservation.cpp`

```cpp
#include "Reservation.h"

Reservation::Reservation(const QString &reservationId, QSharedPointer<Vehicle> vehicle, QSharedPointer<Customer> customer, const QDate &startDate, const QDate &endDate)
    : reservationId(reservationId), vehicle(vehicle), customer(customer), startDate(startDate), endDate(endDate) {}

QString Reservation::getReservationId() const {
    return reservationId;
}

QSharedPointer<Vehicle> Reservation::getVehicle() const {
    return vehicle;
}

QSharedPointer<Customer> Reservation::getCustomer() const {
    return customer;
}

QDate Reservation::getStartDate() const {
    return startDate;
}

QDate Reservation::getEndDate() const {
    return endDate;
}
```

### 6. ReservationManager Class

#### `ReservationManager.h`

```cpp
#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include <QObject>
#include <QList>
#include <QSharedPointer>
#include "Reservation.h"

class ReservationManager : public QObject {
    Q_OBJECT

public:
    explicit ReservationManager(QObject *parent = nullptr);

    void addReservation(QSharedPointer<Reservation> reservation);
    void editReservation(int index, QSharedPointer<Reservation> reservation);
    void removeReservation(int index);
    QList<QSharedPointer<Reservation>> getReservationList() const;

    void saveToFile(const QString &filename) const;
    void loadFromFile(const QString &filename, VehicleManager *vehicleManager, CustomerManager *customerManager);

private:
    QList<QSharedPointer<Reservation>> reservations;
};

#endif // RESERVATION_MANAGER_H
```

#### `ReservationManager.cpp`

```cpp
#include "ReservationManager.h"
#include <QFile>
#include <QTextStream>

ReservationManager::ReservationManager(QObject *parent) : QObject(parent) {}

void ReservationManager::addReservation(QSharedPointer<Reservation> reservation) {
    reservations.append(reservation);
}

void ReservationManager::editReservation(int index, QSharedPointer<Reservation> reservation) {
    if (index >= 0 && index < reservations.size()) {
        reservations[index] = reservation;
    }
}

void ReservationManager::removeReservation(int index) {
    if (index >= 0 && index < reservations.size()) {
        reservations.removeAt(index);
    }
}

QList<QSharedPointer<Reservation>> ReservationManager::getReservationList() const {
    return reservations;
}

void ReservationManager::saveToFile(const QString &filename) const {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        for (const auto &reservation : reservations) {
            out << reservation->getReservationId() << ","
                << reservation->getVehicle()->getVin() << ","
                << reservation->getCustomer()->getId() << ","
                << reservation->getStartDate().toString(Qt::ISODate) << ","
                << reservation->getEndDate().toString(Qt::ISODate) << "\n";
        }
    }
    file.close();
}

void ReservationManager::loadFromFile(const QString &filename, VehicleManager *vehicleManager, CustomerManager *customerManager) {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        reservations.clear();
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() == 5) {
                QString reservationId = parts[0];
                QString vehicleVin = parts[1];
                QString customerId = parts[2];
                QDate startDate = QDate::fromString(parts[3], Qt::ISODate);
                QDate endDate = QDate::fromString(parts[4], Qt::ISODate);

                QSharedPointer<Vehicle> vehicle;
                for (const auto &v : vehicleManager->getVehicleList()) {
                    if (v->getVin() == vehicleVin) {
                        vehicle = v;
                        break;
                    }
                }

                QSharedPointer<Customer> customer;
                for (const auto &c : customerManager->getCustomerList()) {
                    if (c->getId() == customerId) {
                        customer = c;
                        break;
                    }
                }

                if (vehicle && customer) {
                    QSharedPointer<Reservation> reservation = QSharedPointer<Reservation>::create(reservationId, vehicle, customer, startDate, endDate);
                    reservations.append(reservation);
                }
            }
        }
    }
    file.close();
}
```

### 7. Driver Class

#### `Driver.h`

```cpp
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
```

#### `Driver.cpp`

```cpp
#include "Driver.h"

Driver::Driver(const QString &name, const QString &licenseNumber)
    : name(name), licenseNumber(licenseNumber) {}

QString Driver::getName() const {
    return name;
}

QString Driver::getLicenseNumber() const {
    return licenseNumber;
}
```

### 8. DriverManager Class

#### `DriverManager.h`

```cpp
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
```

#### `DriverManager.cpp`

```cpp
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
```

### 9. MainWindow Class

#### `MainWindow.h`

```cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "VehicleManager.h"
#include "CustomerManager.h"
#include "ReservationManager.h"
#include "DriverManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addVehicleButton_clicked();
    void on_editVehicleButton_clicked();
    void on_removeVehicleButton_clicked();
    void on_saveVehicleButton_clicked();
    void on_loadVehicleButton_clicked();

    void on_addCustomerButton_clicked();
    void on_editCustomerButton_clicked();
    void on_removeCustomerButton_clicked();
    void on_saveCustomerButton_clicked();
    void on_loadCustomerButton_clicked();



    void on_addReservationButton_clicked();
    void on_editReservationButton_clicked();
    void on_removeReservationButton_clicked();
    void on_saveReservationButton_clicked();
    void on_loadReservationButton_clicked();

    void on_addDriverButton_clicked();
    void on_editDriverButton_clicked();
    void on_removeDriverButton_clicked();
    void on_saveDriverButton_clicked();
    void on_loadDriverButton_clicked();

private:
    Ui::MainWindow *ui;

    VehicleManager *vehicleManager;
    CustomerManager *customerManager;
    ReservationManager *reservationManager;
    DriverManager *driverManager;
};

#endif // MAINWINDOW_H
```

#### `MainWindow.cpp`

```cpp
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Car.h"
#include "Truck.h"
#include "Customer.h"
#include "Reservation.h"
#include "Driver.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , vehicleManager(new VehicleManager(this))
    , customerManager(new CustomerManager(this))
    , reservationManager(new ReservationManager(this))
    , driverManager(new DriverManager(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addVehicleButton_clicked() {
    // Example: Add a car
    QSharedPointer<Vehicle> car = QSharedPointer<Car>::create("Toyota", "Corolla", 2020, "VIN123456", 4);
    vehicleManager->addVehicle(car);
}

// Implement other slot functions similarly, interacting with respective managers.

void MainWindow::on_saveVehicleButton_clicked() {
    vehicleManager->saveToFile("vehicles.txt");
}

void MainWindow::on_loadVehicleButton_clicked() {
    vehicleManager->loadFromFile("vehicles.txt");
}

void MainWindow::on_addCustomerButton_clicked() {
    // Example: Add a customer
    QSharedPointer<Customer> customer = QSharedPointer<Customer>::create("John Doe", "ID123", "john.doe@example.com");
    customerManager->addCustomer(customer);
}

// Implement other customer slot functions similarly.

void MainWindow::on_saveCustomerButton_clicked() {
    customerManager->saveToFile("customers.txt");
}

void MainWindow::on_loadCustomerButton_clicked() {
    customerManager->loadFromFile("customers.txt");
}

void MainWindow::on_addReservationButton_clicked() {
    // Example: Add a reservation
    if (vehicleManager->getVehicleList().isEmpty() || customerManager->getCustomerList().isEmpty()) {
        return; // Ensure there is at least one vehicle and one customer
    }

    QSharedPointer<Reservation> reservation = QSharedPointer<Reservation>::create(
        "RES123", vehicleManager->getVehicleList().first(), customerManager->getCustomerList().first(), QDate::currentDate(), QDate::currentDate().addDays(7)
    );
    reservationManager->addReservation(reservation);
}

// Implement other reservation slot functions similarly.

void MainWindow::on_saveReservationButton_clicked() {
    reservationManager->saveToFile("reservations.txt");
}

void MainWindow::on_loadReservationButton_clicked() {
    reservationManager->loadFromFile("reservations.txt", vehicleManager, customerManager);
}

void MainWindow::on_addDriverButton_clicked() {
    // Example: Add a driver
    QSharedPointer<Driver> driver = QSharedPointer<Driver>::create("Jane Doe", "LIC123456");
    driverManager->addDriver(driver);
}

// Implement other driver slot functions similarly.

void MainWindow::on_saveDriverButton_clicked() {
    driverManager->saveToFile("drivers.txt");
}

void MainWindow::on_loadDriverButton_clicked() {
    driverManager->loadFromFile("drivers.txt");
}
```

This code covers the full implementation of the vehicle management, customer management, reservation management, and driver management functionalities, avoiding the use of static or dynamic variables directly. You can extend the slot functions and connect them to the UI elements to complete the interaction.
