#include "mainwindow.h"
#include "game.h"
#include "person.h"
#include "patient.h"
#include "guard.h"
#include "doctor.h"
#include "dispstatistics.h"
#include <QApplication>

Game* game;
Patient* patient;
Guard* guard;
Doctor* doctor;
Doctor* bad_doctor;
Guard* bad_guard;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    game = new Game();
    //game->show();

    return a.exec();
}
