#include "patient.h"

/**
 * @brief Standardkonstruktor – erstellt einen leeren Patienten-Datensatz.
 * @author Mohamed Ilahi
 */
Patient::Patient()
{
}

// -------------------- GETTER --------------------

/**
 * @brief Gibt den Titel des Patienten zurück.
 * @author Mohamed Ilahi
 * @return Titel als QString (z. B. „Dr.", „Prof.").
 */
QString Patient::getTitel() const
{
    return titel;
}

/**
 * @brief Gibt den Vornamen des Patienten zurück.
 * @author Mohamed Ilahi
 * @return Vorname als QString.
 */
QString Patient::getVorname() const
{
    return vorname;
}

/**
 * @brief Gibt den Nachnamen des Patienten zurück.
 * @author Mohamed Ilahi
 * @return Nachname als QString.
 */
QString Patient::getNachname() const
{
    return nachname;
}

/**
 * @brief Gibt Straße und Hausnummer der Adresse des Patienten zurück.
 * @author Mohamed Ilahi
 * @return Straße und Hausnummer als QString.
 */
QString Patient::getStrasse() const
{
    return strasse;
}

/**
 * @brief Gibt Postleitzahl und Ort der Adresse des Patienten zurück.
 * @author Mohamed Ilahi
 * @return PLZ und Ort als QString.
 */
QString Patient::getPlzOrt() const
{
    return plzOrt;
}

/**
 * @brief Gibt die Telefonnummer des Patienten zurück.
 * @author Mohamed Ilahi
 * @return Telefonnummer als QString.
 */
QString Patient::getTelefonnummer() const
{
    return telefonnummer;
}

/**
 * @brief Gibt das Geburtsdatum des Patienten zurück.
 * @author Mohamed Ilahi
 * @return Geburtsdatum als QDate.
 */
QDate Patient::getGeburtsdatum() const
{
    return geburtsdatum;
}

/**
 * @brief Gibt das Geschlecht des Patienten zurück.
 * @author Mohamed Ilahi
 * @return Geschlecht als QString.
 */
QString Patient::getGeschlecht() const
{
    return geschlecht;
}

// -------------------- SETTER --------------------

/**
 * @brief Setzt den Titel des Patienten.
 * @author Mohamed Ilahi
 * @param titel Neuer Titel als QString.
 * @note Seiteneffekt: Überschreibt den bisherigen Titel.
 */
void Patient::setTitel(const QString &titel)
{
    this->titel = titel;
}

/**
 * @brief Setzt den Vornamen des Patienten.
 * @author Mohamed Ilahi
 * @param vorname Neuer Vorname als QString.
 * @note Seiteneffekt: Überschreibt den bisherigen Vornamen.
 */
void Patient::setVorname(const QString &vorname)
{
    this->vorname = vorname;
}

/**
 * @brief Setzt den Nachnamen des Patienten.
 * @author Mohamed Ilahi
 * @param nachname Neuer Nachname als QString.
 * @note Seiteneffekt: Überschreibt den bisherigen Nachnamen.
 */
void Patient::setNachname(const QString &nachname)
{
    this->nachname = nachname;
}

/**
 * @brief Setzt Straße und Hausnummer der Adresse des Patienten.
 * @author Mohamed Ilahi
 * @param strasse Neue Straße und Hausnummer als QString.
 * @note Seiteneffekt: Überschreibt die bisherige Straße und Hausnummer.
 */
void Patient::setStrasse(const QString &strasse)
{
    this->strasse = strasse;
}

/**
 * @brief Setzt Postleitzahl und Ort der Adresse des Patienten.
 * @author Mohamed Ilahi
 * @param plz Neue PLZ und Ort als QString.
 * @note Seiteneffekt: Überschreibt die bisherige PLZ und Ort.
 */
void Patient::setPlzOrt(const QString &plzOrt)
{
    this->plzOrt = plzOrt;
}

/**
 * @brief Setzt die Telefonnummer des Patienten.
 * @author Mohamed Ilahi
 * @param telefonnummer Neue Telefonnummer als QString.
 * @note Seiteneffekt: Überschreibt die bisherige Telefonnummer.
 */
void Patient::setTelefonnummer(const QString &telefonnummer)
{
    this->telefonnummer = telefonnummer;
}

/**
 * @brief Setzt das Geburtsdatum des Patienten.
 * @author Mohamed Ilahi
 * @param geburtsdatum Neues Geburtsdatum als QDate.
 * @note Seiteneffekt: Überschreibt das bisherige Geburtsdatum.
 */
void Patient::setGeburtsdatum(const QDate &geburtsdatum)
{
    this->geburtsdatum = geburtsdatum;
}

/**
 * @brief Setzt das Geschlecht des Patienten.
 * @author Mohamed Ilahi
 * @param geschlecht Neues Geschlecht als QString.
 * @note Seiteneffekt: Überschreibt das bisherige Geschlecht.
 */
void Patient::setGeschlecht(const QString &geschlecht)
{
    this->geschlecht = geschlecht;
}
