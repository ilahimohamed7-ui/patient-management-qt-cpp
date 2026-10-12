#include "patientdialog.h"
#include "ui_patientdialog.h"

#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <QRegularExpression>

// -------------------- KONSTRUKTOR --------------------

/**
 * @brief Konstruktor – initialisiert den Patientendialog und konfiguriert die Eingabefelder.
 *
 * Setzt das Anzeigeformat für das Datumsfeld und fügt einen Validator
 * für das Telefonnummernfeld hinzu, der nur Ziffern, „+" und Leerzeichen erlaubt.
 *
 * @author Mohamed Ilahi
 * @param parent Optionaler Eltern-Widget-Zeiger (Standard: nullptr).
 * @note Seiteneffekt: Weist dem Telefonnummer-Eingabefeld einen Regex-Validator zu.
 */
PatientDialog::PatientDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PatientDialog)
{
    ui->setupUi(this);

    // -------------------- DATUM FORMAT --------------------
    ui->dateEditGeburtsdatum->setDisplayFormat("dd.MM.yyyy");

    // -------------------- TELEFON VALIDATOR --------------------
    QRegularExpression phoneRegex("[0-9+ ]+");

    QValidator *phoneValidator =
        new QRegularExpressionValidator(phoneRegex, this);

    ui->lineEditTelefonnummer->setValidator(phoneValidator);
}

// -------------------- DESTRUKTOR --------------------

/**
 * @brief Destruktor – gibt die UI-Ressourcen frei.
 * @author Mohamed Ilahi
 */
PatientDialog::~PatientDialog()
{
    delete ui;
}

// -------------------- PATIENT HOLEN --------------------

/**
 * @brief Liest alle Eingabefelder aus und gibt ein befülltes Patient-Objekt zurück.
 *
 * Erstellt ein neues Patient-Objekt und überträgt alle aktuell eingegebenen
 * Formulardaten (Basisdaten, Adresse, Kontakt, Geburtsdatum, Geschlecht) darauf.
 *
 * @author Mohamed Ilahi
 * @return Patient-Objekt mit den aktuell eingegebenen Formulardaten.
 */
Patient PatientDialog::getPatient() const
{
    Patient p;

    // Basisdaten
    p.setTitel(ui->lineEditTitel->text());
    p.setVorname(ui->lineEditVorname->text());
    p.setNachname(ui->lineEditNachname->text());

    // Adresse
    p.setStrasse(ui->lineEditStrasse->text());

    // PLZ + Ort
    p.setPlzOrt(ui->lineEditPLZOrt->text());

    // Telefonnummer
    p.setTelefonnummer(ui->lineEditTelefonnummer->text());

    // Geburtsdatum
    p.setGeburtsdatum(ui->dateEditGeburtsdatum->date());

    // Geschlecht
    p.setGeschlecht(ui->comboBoxGeschlecht->currentText());

    return p;
}

// -------------------- PATIENT SETZEN --------------------

/**
 * @brief Befüllt alle Eingabefelder mit den Daten eines vorhandenen Patienten.
 *
 * Wird beim Bearbeiten eines bestehenden Patienten aufgerufen, um
 * die aktuellen Werte in die Formularfelder zu laden.
 *
 * @author Mohamed Ilahi
 * @param p Referenz auf das Patient-Objekt, dessen Daten geladen werden sollen.
 * @note Seiteneffekt: Überschreibt den aktuellen Inhalt aller Eingabefelder.
 */
void PatientDialog::setPatient(const Patient &p)
{
    // Basisdaten
    ui->lineEditTitel->setText(p.getTitel());
    ui->lineEditVorname->setText(p.getVorname());
    ui->lineEditNachname->setText(p.getNachname());

    // Adresse
    ui->lineEditStrasse->setText(p.getStrasse());

    // PLZ + Ort
    ui->lineEditPLZOrt->setText(p.getPlzOrt());

    // Telefonnummer
    ui->lineEditTelefonnummer->setText(p.getTelefonnummer());

    // Geburtsdatum
    ui->dateEditGeburtsdatum->setDate(p.getGeburtsdatum());

    // Geschlecht
    ui->comboBoxGeschlecht->setCurrentText(p.getGeschlecht());
}

// -------------------- OK BUTTON --------------------

/**
 * @brief Slot: Validiert alle Pflichtfelder und schließt den Dialog bei Erfolg.
 *
 * Prüft nacheinander, ob Vorname, Nachname, Straße, PLZ/Ort, Telefonnummer
 * und Geschlecht ausgefüllt sind. Bei einem fehlenden Pflichtfeld wird eine
 * Warnung angezeigt und der Dialog bleibt geöffnet. Erst wenn alle Felder
 * gültig sind, wird der Dialog mit @c QDialog::Accepted geschlossen.
 *
 * @author Mohamed Ilahi
 * @note Seiteneffekt: Zeigt bei fehlenden Pflichtfeldern einen Warnhinweis an.
 *       Setzt den Dialog-Rückgabewert auf QDialog::Accepted bei Erfolg.
 */
void PatientDialog::on_pushButtonOk_clicked()
{
    // Vorname prüfen
    if (ui->lineEditVorname->text().trimmed().isEmpty())
    {
        QMessageBox::warning(this, "Fehler", "Bitte Vorname eingeben!");
        return;
    }

    // Nachname prüfen
    if (ui->lineEditNachname->text().trimmed().isEmpty())
    {
        QMessageBox::warning(this, "Fehler", "Bitte Nachname eingeben!");
        return;
    }

    // Straße prüfen
    if (ui->lineEditStrasse->text().trimmed().isEmpty())
    {
        QMessageBox::warning(this, "Fehler", "Bitte Straße eingeben!");
        return;
    }

    // PLZ + Ort prüfen
    if (ui->lineEditPLZOrt->text().trimmed().isEmpty())
    {
        QMessageBox::warning(this, "Fehler", "Bitte PLZ und Ort eingeben!");
        return;
    }

    // Telefonnummer prüfen
    if (ui->lineEditTelefonnummer->text().trimmed().isEmpty())
    {
        QMessageBox::warning(this, "Fehler", "Bitte Telefonnummer eingeben!");
        return;
    }

    // Geschlecht prüfen
    if (ui->comboBoxGeschlecht->currentText().trimmed().isEmpty())
    {
        QMessageBox::warning(this, "Fehler", "Bitte Geschlecht auswählen!");
        return;
    }

    // Alles korrekt
    accept();
}

// -------------------- CANCEL BUTTON --------------------

/**
 * @brief Slot: Verwirft alle Eingaben und schließt den Dialog.
 * @author Mohamed Ilahi
 * @note Seiteneffekt: Setzt den Dialog-Rückgabewert auf QDialog::Rejected.
 */
void PatientDialog::on_pushButtonCancel_clicked()
{
    reject();
}
