#include "patientmanager.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDate>
#include <algorithm>

// -------------------- KONSTRUKTOR --------------------

/**
 * @brief Konstruktor – erstellt einen leeren PatientManager.
 * @author Mohamed Ilahi
 */
PatientManager::PatientManager()
{
}

// -------------------- HINZUFÜGEN --------------------

/**
 * @brief Fügt einen neuen Patienten zur internen Liste hinzu.
 * @author Mohamed Ilahi
 * @param patient Referenz auf das Patient-Objekt, das hinzugefügt werden soll.
 * @note Seiteneffekt: Erweitert den internen @c patients-Vektor um einen Eintrag.
 */
void PatientManager::addPatient(const Patient &patient)
{
    patients.push_back(patient);
}

// -------------------- ZUGRIFF --------------------

/**
 * @brief Gibt eine Referenz auf die interne Patientenliste zurück.
 * @author Mohamed Ilahi
 * @return Referenz auf den internen @c std::vector mit allen Patienten.
 * @note Seiteneffekt: Änderungen an der zurückgegebenen Referenz wirken
 *       sich direkt auf die interne Liste aus.
 */
std::vector<Patient>& PatientManager::getPatients()
{
    return patients;
}

// -------------------- SPEICHERN --------------------

/**
 * @brief Speichert alle Patientendaten zeilenweise in eine Textdatei.
 *
 * Jeder Patient wird als eine Zeile im Format
 * „Titel;Nachname;Vorname;Straße;PLZ;Telefon;Geschlecht;Geburtsdatum"
 * gespeichert. Felder werden durch Semikolon getrennt.
 *
 * @author Mohamed Ilahi
 * @param filename Pfad und Name der Zieldatei als QString.
 * @note Seiteneffekt: Erstellt oder überschreibt die angegebene Datei.
 *       Bricht stillschweigend ab, wenn die Datei nicht geöffnet werden kann.
 */
void PatientManager::saveToFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for (const Patient &p : patients)
    {
        out << p.getTitel() << ";"
            << p.getNachname() << ";"
            << p.getVorname() << ";"
            << p.getStrasse() << ";"
            << p.getPlzOrt() << ";"
            << p.getTelefonnummer() << ";"
            << p.getGeschlecht() << ";"
            << p.getGeburtsdatum().toString("dd.MM.yyyy")
            << "\n";
    }
}

// -------------------- LADEN --------------------

/**
 * @brief Lädt Patientendaten aus einer Textdatei in die interne Liste.
 *
 * Liest die Datei zeilenweise ein. Jede Zeile muss genau 8 durch Semikolon
 * getrennte Felder im Format „Titel;Nachname;Vorname;Straße;PLZ;Telefon;
 * Geschlecht;Geburtsdatum" enthalten. Zeilen mit abweichender Feldanzahl
 * werden übersprungen.
 *
 * @author Mohamed Ilahi
 * @param filename Pfad und Name der Quelldatei als QString.
 * @note Seiteneffekt: Leert die aktuelle interne Patientenliste vollständig
 *       und befüllt sie mit den geladenen Daten. Bricht stillschweigend ab,
 *       wenn die Datei nicht geöffnet werden kann.
 */
void PatientManager::loadFromFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    patients.clear();

    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        if (line.isEmpty())
            continue;

        QStringList parts = line.split(";");
        if (parts.size() != 8)
            continue;

        Patient p;
        p.setTitel(parts[0]);
        p.setNachname(parts[1]);
        p.setVorname(parts[2]);
        p.setStrasse(parts[3]);
        p.setPlzOrt(parts[4]);
        p.setTelefonnummer(parts[5]);
        p.setGeschlecht(parts[6]);
        p.setGeburtsdatum(QDate::fromString(parts[7], "dd.MM.yyyy"));
        patients.push_back(p);
    }
}

// -------------------- SORTIEREN --------------------

/**
 * @brief Sortiert die Patientenliste alphabetisch nach Nachname, Vorname
 *        und anschließend nach Geburtsdatum.
 *
 * Die Sortierung erfolgt primär nach Nachname, bei Gleichheit nach Vorname
 * und bei weiterer Gleichheit nach Geburtsdatum (aufsteigend).
 *
 * @author Mohamed Ilahi
 * @note Seiteneffekt: Verändert die Reihenfolge der Einträge im internen
 *       @c patients-Vektor dauerhaft.
 */
void PatientManager::sortPatients()
{
    std::sort(patients.begin(), patients.end(),
              [](const Patient &a, const Patient &b)
              {
                  if (a.getNachname() != b.getNachname())
                      return a.getNachname() < b.getNachname();
                  if (a.getVorname() != b.getVorname())
                      return a.getVorname() < b.getVorname();
                  return a.getGeburtsdatum() < b.getGeburtsdatum();
              });
}
