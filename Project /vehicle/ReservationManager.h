#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include <QObject>
#include <QList>
#include <QSharedPointer>
#include "Reservation.h"
#include "CustomerManager.h"
#include "VehicleManager.h"
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
