#include "controller.h"
#include "ui_controller.h"

Controller::Controller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controller)
{
    ui->setupUi(this);
    //initialize
    ui->CurrentMotorHorizontalSlider->setRange(0,1000);
    ui->CapacitorHorizontalSlider->setRange(0,111);
    ui->Cycle_usHorizontalSlider->setRange(0,111);
    ui->BatteryHorizontalSlider->setRange(0,111);
}

Controller::~Controller()
{
    delete ui;
}

void Controller::on_CurrentMotorHorizontalSlider_sliderMoved(int position)
{

}

void Controller::on_Cycle_usHorizontalSlider_sliderMoved(int position)
{

}
