#ifndef PATIENTDIALOG_H
#define PATIENTDIALOG_H

#include <QDialog>
#include "patient.h"

namespace Ui {
class PatientDialog;
}

/**
 * @brief Dialogfenster zum Hinzufügen und Bearbeiten von Patientendaten.
 *
 * Dieser Dialog stellt Eingabefelder für alle Patientenattribute bereit
 * und wird sowohl beim Anlegen neuer Patienten als auch beim Bearbeiten
 * bestehender Einträge verwendet. Über @c getPatient() können die
 * eingegebenen Daten als Patient-Objekt abgerufen werden.
 *
 * @author Mohamed Ilahi
 */
class PatientDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor – erstellt den Dialog und initialisiert die UI.
     * @param parent Optionaler Eltern-Widget-Zeiger (Standard: nullptr).
     */
    explicit PatientDialog(QWidget *parent = nullptr);

    /**
     * @brief Destruktor – gibt die UI-Ressourcen frei.
     */
    ~PatientDialog();

    /**
     * @brief Liest alle Eingabefelder aus und gibt das erzeugte Patient-Objekt zurück.
     * @return Patient-Objekt mit den aktuell eingegebenen Formulardaten.
     */
    Patient getPatient() const;

    /**
     * @brief Befüllt alle Eingabefelder mit den Daten eines vorhandenen Patienten.
     *
     * Wird beim Bearbeiten eines bestehenden Patienten aufgerufen, um
     * die aktuellen Werte in die Formularfelder zu laden.
     *
     * @param p Referenz auf das Patient-Objekt, dessen Daten geladen werden sollen.
     * @note Seiteneffekt: Überschreibt den aktuellen Inhalt aller Eingabefelder.
     */
    void setPatient(const Patient &p);

private slots:
    /**
     * @brief Slot: Wird ausgelöst, wenn der „OK"-Button geklickt wird.
     * @brief Bestätigt die Eingabe und schließt den Dialog mit Accept-Status.
     * @note Seiteneffekt: Setzt den Dialog-Rückgabewert auf QDialog::Accepted.
     */
    void on_pushButtonOk_clicked();

    /**
     * @brief Slot: Wird ausgelöst, wenn der „Abbrechen"-Button geklickt wird.
     * @brief Verwirft alle Eingaben und schließt den Dialog mit Reject-Status.
     * @note Seiteneffekt: Setzt den Dialog-Rückgabewert auf QDialog::Rejected.
     */
    void on_pushButtonCancel_clicked();

private:
    /** @brief Zeiger auf die generierte UI-Klasse des Dialogs. */
    Ui::PatientDialog *ui;
};

#endif // PATIENTDIALOG_H
