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
