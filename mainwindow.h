#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "patientmanager.h"
#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Hauptfenster der Anwendung zur Verwaltung von Patientendaten.
 *
 * Diese Klasse stellt die grafische Benutzeroberfläche bereit und verbindet
 * die UI-Elemente mit dem PatientManager. Sie ermöglicht das Anzeigen,
 * Hinzufügen, Bearbeiten und Löschen von Patienten sowie das Filtern
 * der Patientenliste.
 *
 * @author Mohamed Ilahi
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor – erstellt das Hauptfenster und initialisiert die UI.
     * @param parent Optionaler Eltern-Widget-Zeiger (Standard: nullptr).
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destruktor – gibt die UI-Ressourcen frei.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Slot: Wird ausgelöst, wenn der „Anzeigen"-Button geklickt wird.
     * @brief Wendet den aktuellen Filter an und aktualisiert die Patientenliste.
     */
    void on_pushButtonShow_clicked();

    /**
     * @brief Slot: Wird ausgelöst, wenn der „Hinzufügen"-Button geklickt wird.
     * @brief Öffnet einen Dialog zum Erfassen eines neuen Patienten.
     */
    void on_pushButtonAdd_clicked();

    /**
     * @brief Slot: Wird ausgelöst, wenn der „Bearbeiten"-Button geklickt wird.
     * @brief Öffnet einen Dialog zum Bearbeiten des ausgewählten Patienten.
     * @note Seiteneffekt: Ändert den Eintrag im PatientManager.
     */
    void on_pushButtonEdit_clicked();

    /**
     * @brief Slot: Wird ausgelöst, wenn der „Löschen"-Button geklickt wird.
     * @brief Entfernt den aktuell ausgewählten Patienten aus dem PatientManager.
     * @note Seiteneffekt: Löscht den Eintrag dauerhaft aus der Verwaltung.
     */
    void on_pushButtonDelete_clicked();

    /**
     * @brief Slot: Wird ausgelöst, wenn der „Auswahl aufheben"-Button geklickt wird.
     * @brief Hebt die aktuelle Tabellenauswahl auf.
     */
    void on_pushButtonClearSelection_clicked();

private:
    /** @brief Zeiger auf die generierte UI-Klasse. */
    Ui::MainWindow *ui;

    /** @brief Instanz des PatientManagers zur Datenverwaltung. */
    PatientManager manager;

    /**
     * @brief Gefilterte Index-Liste – bildet Tabellenzeilen auf Manager-Indizes ab.
     *
     * Enthält die Original-Indizes der Patienten im PatientManager,
     * die dem aktuellen Filter entsprechen. Notwendig für korrektes
     * Bearbeiten und Löschen nach einer Filterung.
     */
    QVector<int> m_filteredIndices;

    /**
     * @brief Lädt Testdaten in den PatientManager.
     * @note Seiteneffekt: Befüllt den PatientManager mit vordefinierten Einträgen.
     */
    void loadTestData();

    /**
     * @brief Wendet den aktuellen Suchfilter an und aktualisiert die Tabelle.
     * @note Seiteneffekt: Aktualisiert m_filteredIndices und die UI-Tabelle.
     */
    void applyFilter();

    /**
     * @brief Gibt den aktuell in der Tabelle ausgewählten Patienten zurück.
     * @return Patient-Objekt der ausgewählten Zeile.
     * @note Seiteneffekt: Keine. Liest nur die aktuelle Auswahl aus.
     */
    Patient getSelectedPatient();
};

#endif // MAINWINDOW_H
