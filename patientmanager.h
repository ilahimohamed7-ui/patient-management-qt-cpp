#ifndef PATIENTMANAGER_H
#define PATIENTMANAGER_H

#include <vector>
#include <QString>
#include "patient.h"

/**
 * @brief Verwaltet eine Liste von Patienten und bietet Operationen zur Datenverwaltung.
 *
 * Diese Klasse dient als zentrale Verwaltungseinheit für alle Patientendaten.
 * Sie ermöglicht das Hinzufügen, Abrufen, Sortieren sowie das persistente
 * Speichern und Laden von Patienten über eine Datei.
 *
 * @author Mohamed Ilahi
 */
class PatientManager
{
public:
    /**
     * @brief Konstruktor – erstellt einen leeren PatientManager.
     */
    PatientManager();

    /**
     * @brief Fügt einen neuen Patienten zur Verwaltungsliste hinzu.
     * @param patient Referenz auf das Patient-Objekt, das hinzugefügt werden soll.
     * @note Seiteneffekt: Erweitert die interne Patientenliste um einen Eintrag.
     */
    void addPatient(const Patient &patient);

    /**
     * @brief Gibt eine Referenz auf die interne Patientenliste zurück.
     * @return Referenz auf den internen std::vector mit allen Patienten.
     * @note Seiteneffekt: Änderungen an der zurückgegebenen Referenz wirken
     *       sich direkt auf die interne Liste aus.
     */
    std::vector<Patient>& getPatients();

    /**
     * @brief Speichert alle Patientendaten in eine Datei.
     * @param filename Pfad und Name der Zieldatei als QString.
     * @note Seiteneffekt: Erstellt oder überschreibt die angegebene Datei.
     */
    void saveToFile(const QString &filename);

    /**
     * @brief Lädt Patientendaten aus einer Datei in die interne Liste.
     * @param filename Pfad und Name der Quelldatei als QString.
     * @note Seiteneffekt: Überschreibt die aktuelle interne Patientenliste
     *       mit den geladenen Daten.
     */
    void loadFromFile(const QString &filename);

    /**
     * @brief Sortiert die Patientenliste alphabetisch nach Nachnamen.
     * @note Seiteneffekt: Verändert die Reihenfolge der Einträge in der
     *       internen Patientenliste.
     */
    void sortPatients();

private:
    /** @brief Interne Liste aller verwalteten Patienten. */
    std::vector<Patient> patients;
};

#endif // PATIENTMANAGER_H
