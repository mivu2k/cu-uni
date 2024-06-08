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
