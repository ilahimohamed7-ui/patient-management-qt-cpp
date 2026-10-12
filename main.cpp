#include "mainwindow.h"
#include <QApplication>

/**
 * @brief Einstiegspunkt der Anwendung.
 *
 * Initialisiert die Qt-Anwendung, erstellt das Hauptfenster und
 * startet die Ereignisschleife.
 *
 * @author Mohamed Ilahi
 * @param argc Anzahl der Kommandozeilenargumente.
 * @param argv Array der Kommandozeilenargumente als C-Strings.
 * @return Rückgabewert der Qt-Ereignisschleife (0 bei normalem Beenden).
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
