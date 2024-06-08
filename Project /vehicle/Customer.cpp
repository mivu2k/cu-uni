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
