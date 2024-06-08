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
