#ifndef PATIENTDETAILSDIALOG_H
#define PATIENTDETAILSDIALOG_H

#include <QDialog>
#include "patient.h"

namespace Ui {
class PatientDetailsDialog;
}

/**
 * @brief Dialog zur Anzeige der vollständigen Details eines Patienten.
 *
 * Dieser Dialog öffnet sich im Lesemodus und zeigt alle gespeicherten
 * Informationen eines ausgewählten Patienten an. Eine Bearbeitung der
 * Daten ist in diesem Dialog nicht vorgesehen.
 *
 * @author Mohamed Ilahi
 */
class PatientDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor – erstellt den Dialog und initialisiert die UI.
     * @param parent Optionaler Eltern-Widget-Zeiger (Standard: nullptr).
     */
    explicit PatientDetailsDialog(QWidget *parent = nullptr);

    /**
     * @brief Destruktor – gibt die UI-Ressourcen frei.
     */
    ~PatientDetailsDialog();

    /**
     * @brief Befüllt die UI-Felder mit den Daten des übergebenen Patienten.
     * @param p Referenz auf das Patient-Objekt, dessen Daten angezeigt werden sollen.
     * @note Seiteneffekt: Aktualisiert alle Anzeigefelder im Dialog.
     */
    void setPatient(const Patient &p);

private slots:
    /**
     * @brief Slot: Wird ausgelöst, wenn der „Zurück"-Button geklickt wird.
     * @brief Schließt den Dialog und kehrt zum Hauptfenster zurück.
     */
    void on_pushButtonZurueck_clicked();

private:
    /** @brief Zeiger auf die generierte UI-Klasse des Dialogs. */
    Ui::PatientDetailsDialog *ui;
};

#endif // PATIENTDETAILSDIALOG_H
