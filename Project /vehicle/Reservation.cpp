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
