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
