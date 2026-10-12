#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QDate>

/**
 * @brief Speichert alle persönlichen und medizinischen Basisdaten eines Patienten.
 *
 * Diese Klasse dient als Datenmodell für einen einzelnen Patienten.
 * Sie enthält persönliche Angaben (Name, Titel, Geschlecht, Geburtsdatum),
 * Adressdaten sowie Kontaktinformationen und stellt entsprechende
 * Getter- und Setter-Methoden bereit.
 *
 * @author Mohamed Ilahi
 */
class Patient
{
public:
    /**
     * @brief Standardkonstruktor – erstellt einen leeren Patienten-Datensatz.
     */
    Patient();

    // -------------------- GETTER --------------------

    /**
     * @brief Gibt den Titel des Patienten zurück.
     * @return Titel als QString (z. B. „Dr.", „Prof.").
     */
    QString getTitel() const;

    /**
     * @brief Gibt den Vornamen des Patienten zurück.
     * @return Vorname als QString.
     */
    QString getVorname() const;

    /**
     * @brief Gibt den Nachnamen des Patienten zurück.
     * @return Nachname als QString.
     */
    QString getNachname() const;

    /**
     * @brief Gibt Straße und Hausnummer der Adresse des Patienten zurück.
     * @return Straße und Hausnummer als QString.
     */
    QString getStrasse() const;

    /**
     * @brief Gibt Postleitzahl und Ort der Adresse des Patienten zurück.
     * @return PLZ und Ort als QString.
     */
    QString getPlzOrt() const;

    /**
     * @brief Gibt die Telefonnummer des Patienten zurück.
     * @return Telefonnummer als QString.
     */
    QString getTelefonnummer() const;

    /**
     * @brief Gibt das Geburtsdatum des Patienten zurück.
     * @return Geburtsdatum als QDate.
     */
    QDate getGeburtsdatum() const;

    /**
     * @brief Gibt das Geschlecht des Patienten zurück.
     * @return Geschlecht als QString (z. B. „männlich", „weiblich", „divers").
     */
    QString getGeschlecht() const;

    // -------------------- SETTER --------------------

    /**
     * @brief Setzt den Titel des Patienten.
     * @param titel Neuer Titel als QString.
     */
    void setTitel(const QString &titel);

    /**
     * @brief Setzt den Vornamen des Patienten.
     * @param vorname Neuer Vorname als QString.
     */
    void setVorname(const QString &vorname);

    /**
     * @brief Setzt den Nachnamen des Patienten.
     * @param nachname Neuer Nachname als QString.
     */
    void setNachname(const QString &nachname);

    /**
     * @brief Setzt Straße und Hausnummer der Adresse des Patienten.
     * @param strasse Neue Straße und Hausnummer als QString.
     */
    void setStrasse(const QString &strasse);

    /**
     * @brief Setzt Postleitzahl und Ort der Adresse des Patienten.
     * @param plz Neue PLZ und Ort als QString.
     */
    void setPlzOrt(const QString &plzOrt);

    /**
     * @brief Setzt die Telefonnummer des Patienten.
     * @param telefonnummer Neue Telefonnummer als QString.
     */
    void setTelefonnummer(const QString &telefonnummer);

    /**
     * @brief Setzt das Geburtsdatum des Patienten.
     * @param geburtsdatum Neues Geburtsdatum als QDate.
     */
    void setGeburtsdatum(const QDate &geburtsdatum);

    /**
     * @brief Setzt das Geschlecht des Patienten.
     * @param geschlecht Neues Geschlecht als QString.
     */
    void setGeschlecht(const QString &geschlecht);

private:
    // -------------------- PERSON --------------------

    /** @brief Akademischer oder sonstiger Titel des Patienten. */
    QString titel;

    /** @brief Vorname des Patienten. */
    QString vorname;

    /** @brief Nachname des Patienten. */
    QString nachname;

    // -------------------- ADRESSE --------------------

    /** @brief Straße und Hausnummer der Wohnadresse. */
    QString strasse;

    /** @brief Postleitzahl und Ort der Wohnadresse. */
    QString plzOrt;

    // -------------------- KONTAKT --------------------

    /** @brief Telefonnummer des Patienten. */
    QString telefonnummer;

    // -------------------- WEITERE DATEN --------------------

    /** @brief Geburtsdatum des Patienten. */
    QDate geburtsdatum;

    /** @brief Geschlecht des Patienten. */
    QString geschlecht;
};

#endif // PATIENT_H
