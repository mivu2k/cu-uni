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
