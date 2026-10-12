#include "patientdetailsdialog.h"
#include "ui_patientdetailsdialog.h"

// -------------------- KONSTRUKTOR --------------------

/**
 * @brief Konstruktor – initialisiert den Detaildialog und fixiert die Fenstergröße.
 * @author Mohamed Ilahi
 * @param parent Optionaler Eltern-Widget-Zeiger (Standard: nullptr).
 * @note Seiteneffekt: Setzt die Fenstergröße auf einen fixen Wert.
 */
PatientDetailsDialog::PatientDetailsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PatientDetailsDialog)
{
    ui->setupUi(this);
    // Fenstergröße fixieren (optional)
    setFixedSize(size());
}

// -------------------- DESTRUKTOR --------------------

/**
 * @brief Destruktor – gibt die UI-Ressourcen frei.
 * @author Mohamed Ilahi
 */
PatientDetailsDialog::~PatientDetailsDialog()
{
    delete ui;
}

// -------------------- PATIENT SETZEN --------------------

/**
 * @brief Befüllt alle Anzeigefelder des Dialogs mit den Daten des übergebenen Patienten.
 * @author Mohamed Ilahi
 * @param p Referenz auf das Patient-Objekt, dessen Daten angezeigt werden sollen.
 * @note Seiteneffekt: Aktualisiert alle Label-Felder in der UI mit den Patientendaten.
 */
void PatientDetailsDialog::setPatient(const Patient &p)
{
    ui->labelTitelWert->setText(p.getTitel());
    ui->labelVornameWert->setText(p.getVorname());
    ui->labelNachnameWert->setText(p.getNachname());
    ui->labelStrasseWert->setText(p.getStrasse());
    ui->labelPLZOrtWert->setText(p.getPlzOrt());
    ui->labelTelefonWert->setText(p.getTelefonnummer());
    ui->labelGeschlechtWert->setText(p.getGeschlecht());
    ui->labelGeburtsdatumWert->setText(
        p.getGeburtsdatum().toString("dd.MM.yyyy"));
}

// -------------------- ZURÜCK BUTTON --------------------

/**
 * @brief Slot: Schließt den Detaildialog und kehrt zum Hauptfenster zurück.
 * @author Mohamed Ilahi
 * @note Seiteneffekt: Schließt das Dialogfenster.
 */
void PatientDetailsDialog::on_pushButtonZurueck_clicked()
{
    close();
}
