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
