#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "person.h"
#include "patient.h"
#include "game.h"
#include <QDebug>


extern Person* person;
extern Patient* patient;
extern Game* game;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_setName_ok_clicked(){

    patient->setName(ui->name_txt->text());
    ui->name_txt->clear();
}


void MainWindow::on_play_btn_clicked(){
    if(patient->name != QString("")){
        game->stats->updateStats();
        game->show();
        this->close();
    }
    else
        ui->name_txt->setText(QString("Enter your name first"));
}

void MainWindow::on_exit_btn_clicked(){
    this->close();
}

