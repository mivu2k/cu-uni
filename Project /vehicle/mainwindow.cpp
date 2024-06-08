#include "MainWindow.h"
#include "//ui_mainwindow.h"
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
