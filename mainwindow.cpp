#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patient.h"
#include "patientdialog.h"
#include "patientdetailsdialog.h"
#include <QDate>
#include <QLineEdit>
#include <QMessageBox>
#include <QStyle>
#include <QIcon>

// -------------------- STYLESHEET --------------------

/**
 * @brief Globales Stylesheet der Anwendung.
 *
 * Definiert das visuelle Erscheinungsbild aller UI-Elemente
 * im Hauptfenster und den zugehörigen Dialogen.
 *
 * @author Mohamed Ilahi
 */
static const QString APP_STYLE = R"(
    QMainWindow {
        background-color: #F0F4F8;
    }
    QWidget {
        background-color: #F0F4F8;
        font-family: "Segoe UI", sans-serif;
        font-size: 10pt;
        color: #1A2B3C;
    }
    QGroupBox {
        background-color: #FFFFFF;
        border: none;
        border-radius: 12px;
        margin-top: 10px;
        padding: 16px;
        font-weight: bold;
        font-size: 10pt;
        color: #4A6FA5;
    }
    QGroupBox::title {
        subcontrol-origin: margin;
        subcontrol-position: top left;
        padding: 0 8px;
        color: #4A6FA5;
        font-size: 9pt;
        letter-spacing: 1px;
        text-transform: uppercase;
    }
    QLineEdit, QDateEdit {
        background-color: #F7FAFC;
        border: 1.5px solid #CBD5E0;
        border-radius: 8px;
        padding: 7px 12px;
        color: #1A2B3C;
        font-size: 10pt;
    }
    QLineEdit:focus, QDateEdit:focus {
        border: 1.5px solid #4A6FA5;
        background-color: #FFFFFF;
    }
    QCheckBox {
        color: #4A5568;
        spacing: 8px;
        font-size: 9pt;
    }
    QCheckBox::indicator {
        width: 16px;
        height: 16px;
        border-radius: 4px;
        border: 1.5px solid #CBD5E0;
        background: #FFFFFF;
    }
    QCheckBox::indicator:checked {
        background-color: #4A6FA5;
        border: 1.5px solid #4A6FA5;
    }
    QListWidget {
        background-color: #FFFFFF;
        border: none;
        border-radius: 12px;
        padding: 8px;
        font-size: 10pt;
        outline: none;
    }
    QListWidget::item {
        padding: 10px 14px;
        border-radius: 8px;
        margin: 2px 0;
        color: #2D3748;
        border-left: 3px solid transparent;
    }
    QListWidget::item:alternate {
        background-color: #F7FAFC;
    }
    QListWidget::item:hover {
        background-color: #EBF4FF;
        border-left: 3px solid #90B8E0;
    }
    QListWidget::item:selected {
        background-color: #DBEAFE;
        color: #1A365D;
        border-left: 3px solid #4A6FA5;
        font-weight: bold;
    }
    QPushButton {
        background-color: #4A6FA5;
        color: #FFFFFF;
        border: none;
        border-radius: 8px;
        padding: 8px 16px;
        font-size: 9pt;
        font-weight: bold;
        letter-spacing: 0.3px;
        min-width: 90px;
        text-align: left;
    }
    QPushButton:hover  { background-color: #3A5A8A; }
    QPushButton:pressed { background-color: #2C4A75; }

    QPushButton#pushButtonDelete {
        background-color: #E53E3E;
    }
    QPushButton#pushButtonDelete:hover  { background-color: #C53030; }
    QPushButton#pushButtonDelete:pressed { background-color: #9B2C2C; }

    QPushButton#pushButtonClearSelection {
        background-color: transparent;
        color: #718096;
        border: 1.5px solid #CBD5E0;
        font-weight: normal;
        text-align: left;
    }
    QPushButton#pushButtonClearSelection:hover {
        background-color: #EDF2F7;
        color: #4A5568;
        border-color: #A0AEC0;
    }
    QScrollBar:vertical {
        background: #F0F4F8;
        width: 8px;
        border-radius: 4px;
    }
    QScrollBar::handle:vertical {
        background: #CBD5E0;
        border-radius: 4px;
        min-height: 30px;
    }
    QScrollBar::handle:vertical:hover { background: #A0AEC0; }
    QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0; }

    QMenuBar {
        background-color: #FFFFFF;
        border-bottom: 1px solid #E2E8F0;
        padding: 2px 8px;
        color: #2D3748;
    }
    QMenuBar::item:selected {
        background-color: #EBF4FF;
        border-radius: 4px;
        color: #4A6FA5;
    }
    QStatusBar {
        background-color: #FFFFFF;
        border-top: 1px solid #E2E8F0;
        color: #718096;
        font-size: 8pt;
    }
)";

// -------------------- KONSTRUKTOR --------------------

/**
 * @brief Konstruktor – initialisiert das Hauptfenster und alle UI-Komponenten.
 *
 * Setzt das Stylesheet, den Fenstertitel, die Icons der Buttons sowie
 * die Signal-Slot-Verbindungen für die Filterfelder. Lädt außerdem
 * vorhandene Patientendaten aus der Datei und zeigt sie an.
 *
 * @author Mohamed Ilahi
 * @param parent Optionaler Eltern-Widget-Zeiger (Standard: nullptr).
 * @note Seiteneffekt: Lädt Patientendaten aus „patients.txt" und befüllt die Liste.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet(APP_STYLE);
    this->setWindowTitle("Patientenverwaltung");
    this->resize(700, 540);

    // Fenster-Icon
    this->setWindowIcon(style()->standardIcon(QStyle::SP_FileDialogDetailedView));

    ui->listePatienten->setAlternatingRowColors(true);

    // -------------------- ICONS FÜR BUTTONS --------------------
    ui->pushButtonShow->setIcon(style()->standardIcon(QStyle::SP_FileDialogContentsView));
    ui->pushButtonShow->setIconSize(QSize(16, 16));
    ui->pushButtonShow->setText("  Anzeigen");

    ui->pushButtonAdd->setIcon(style()->standardIcon(QStyle::SP_FileDialogNewFolder));
    ui->pushButtonAdd->setIconSize(QSize(16, 16));
    ui->pushButtonAdd->setText("  Hinzufügen");

    ui->pushButtonEdit->setIcon(style()->standardIcon(QStyle::SP_FileIcon));
    ui->pushButtonEdit->setIconSize(QSize(16, 16));
    ui->pushButtonEdit->setText("  Bearbeiten");

    ui->pushButtonDelete->setIcon(style()->standardIcon(QStyle::SP_TrashIcon));
    ui->pushButtonDelete->setIconSize(QSize(16, 16));
    ui->pushButtonDelete->setText("  Löschen");

    // Auswahl aufheben — Pfeil zurück (Reset-Symbol)
    ui->pushButtonClearSelection->setIcon(style()->standardIcon(QStyle::SP_BrowserReload));
    ui->pushButtonClearSelection->setIconSize(QSize(14, 14));
    ui->pushButtonClearSelection->setText("  Auswahl aufheben");


    QAction *iconNachname = new QAction(
        style()->standardIcon(QStyle::SP_FileDialogContentsView), "", this);
    ui->lineEditNachname->addAction(iconNachname, QLineEdit::LeadingPosition);

    QAction *iconVorname = new QAction(
        style()->standardIcon(QStyle::SP_FileDialogContentsView), "", this);
    ui->lineEditVorname->addAction(iconVorname, QLineEdit::LeadingPosition);



    // -------------------- SIGNALS --------------------
    connect(ui->lineEditNachname, &QLineEdit::textChanged, this, &MainWindow::applyFilter);
    connect(ui->lineEditVorname,  &QLineEdit::textChanged, this, &MainWindow::applyFilter);
    connect(ui->edtSucheDatum,    &QDateEdit::dateChanged, this, &MainWindow::applyFilter);
    connect(ui->chkDatumAktiv,    &QCheckBox::toggled,     this, &MainWindow::applyFilter);

    // -------------------- DATEN LADEN --------------------
    manager.loadFromFile("patients.txt");
    applyFilter();
}

// -------------------- DESTRUKTOR --------------------

/**
 * @brief Destruktor – speichert alle Patientendaten und gibt UI-Ressourcen frei.
 * @author Mohamed Ilahi
 * @note Seiteneffekt: Schreibt die aktuelle Patientenliste in „patients.txt".
 */
MainWindow::~MainWindow()
{
    manager.saveToFile("patients.txt");
    delete ui;
}

// -------------------- FILTER --------------------

/**
 * @brief Wendet die aktuellen Filterkriterien auf die Patientenliste an.
 *
 * Liest die Eingabefelder für Nachname, Vorname und optional Geburtsdatum aus,
 * filtert die Patientenliste des Managers entsprechend und aktualisiert
 * die Anzeige sowie das Mapping-Array @c m_filteredIndices.
 *
 * @author Mohamed Ilahi
 * @note Seiteneffekt: Leert und befüllt die ListWidget-Anzeige neu.
 *       Aktualisiert @c m_filteredIndices mit den passenden Original-Indizes.
 *       Zeigt die Anzahl gefundener Patienten in der Statusleiste an.
 */
void MainWindow::applyFilter()
{
    manager.sortPatients();

    QString nachnameFilter = ui->lineEditNachname->text().toLower();
    QString vornameFilter  = ui->lineEditVorname->text().toLower();
    bool datumAktiv        = ui->chkDatumAktiv->isChecked();

    QString geburtsdatumFilter;
    if (datumAktiv)
        geburtsdatumFilter = ui->edtSucheDatum->date().toString("dd.MM.yyyy");

    auto patients = manager.getPatients();
    ui->listePatienten->clear();
    m_filteredIndices.clear();

    for (size_t i = 0; i < patients.size(); i++) {
        const Patient &p = patients[i];
        QString nachname = p.getNachname().toLower();
        QString vorname  = p.getVorname().toLower();
        QString gebDatum = p.getGeburtsdatum().toString("dd.MM.yyyy");

        bool match = (nachname.contains(nachnameFilter) || nachnameFilter.isEmpty())
                     && (vorname.contains(vornameFilter)   || vornameFilter.isEmpty())
                     && (!datumAktiv || gebDatum.contains(geburtsdatumFilter));

        if (match) {
            QString text = p.getTitel() + " " + p.getNachname() + ", " + p.getVorname()
                           + "   |   " + gebDatum;

            QListWidgetItem *item = new QListWidgetItem(
                style()->standardIcon(QStyle::SP_FileDialogDetailedView),
                text
                );
            ui->listePatienten->addItem(item);
            m_filteredIndices.push_back(i);
        }
    }

    ui->listePatienten->clearSelection();
    ui->statusbar->showMessage(
        QString("  👥  %1 Patient(en) gefunden").arg(m_filteredIndices.size())
        );
}

// -------------------- AUSGEWÄHLTEN PATIENT HOLEN --------------------

/**
 * @brief Gibt den aktuell in der Liste ausgewählten Patienten zurück.
 *
 * Ermittelt anhand der aktuellen Zeilenauswahl und des Mapping-Arrays
 * @c m_filteredIndices den zugehörigen Original-Index im PatientManager.
 *
 * @author Mohamed Ilahi
 * @return Patient-Objekt der ausgewählten Zeile, oder leerer Patient bei
 *         ungültiger Auswahl.
 */
Patient MainWindow::getSelectedPatient()
{
    int row = ui->listePatienten->currentRow();
    if (row < 0 || row >= m_filteredIndices.size()) return Patient();
    return manager.getPatients()[m_filteredIndices[row]];
}

// -------------------- ANZEIGEN --------------------

/**
 * @brief Slot: Öffnet den Detaildialog für den ausgewählten Patienten.
 *
 * Prüft, ob ein Patient ausgewählt wurde, und öffnet bei gültiger
 * Auswahl den @c PatientDetailsDialog mit den entsprechenden Daten.
 *
 * @author Mohamed Ilahi
 * @note Seiteneffekt: Öffnet einen modalen Dialog. Zeigt eine Warnung,
 *       falls kein Patient ausgewählt ist.
 */
void MainWindow::on_pushButtonShow_clicked()
{
    Patient p = getSelectedPatient();
    if (p.getNachname().isEmpty()) {
        QMessageBox::warning(this, "Hinweis", "Bitte einen Patienten auswählen!");
        return;
    }
    PatientDetailsDialog dlg(this);
    dlg.setPatient(p);
    dlg.exec();
}

// -------------------- HINZUFÜGEN --------------------

/**
 * @brief Slot: Öffnet den Eingabedialog zum Anlegen eines neuen Patienten.
 *
 * Bei Bestätigung des Dialogs wird der neue Patient dem Manager hinzugefügt,
 * die Liste neu sortiert und die Anzeige aktualisiert.
 *
 * @author Mohamed Ilahi
 * @note Seiteneffekt: Fügt einen neuen Eintrag in den PatientManager ein
 *       und aktualisiert die Listenansicht.
 */
void MainWindow::on_pushButtonAdd_clicked()
{
    PatientDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        manager.addPatient(dlg.getPatient());
        manager.sortPatients();
        applyFilter();
    }
}

// -------------------- BEARBEITEN --------------------

/**
 * @brief Slot: Öffnet den Bearbeitungsdialog für den ausgewählten Patienten.
 *
 * Lädt die Daten des ausgewählten Patienten in den @c PatientDialog.
 * Bei Bestätigung wird der Eintrag im Manager über den Original-Index
 * aus @c m_filteredIndices aktualisiert.
 *
 * @author Mohamed Ilahi
 * @note Seiteneffekt: Überschreibt den bestehenden Patienteneintrag im Manager
 *       und aktualisiert die Listenansicht. Zeigt eine Warnung, falls kein
 *       Patient ausgewählt ist.
 */
void MainWindow::on_pushButtonEdit_clicked()
{
    Patient p = getSelectedPatient();
    if (p.getNachname().isEmpty()) {
        QMessageBox::warning(this, "Hinweis", "Bitte einen Patienten auswählen!");
        return;
    }
    PatientDialog dlg(this);
    dlg.setPatient(p);
    if (dlg.exec() == QDialog::Accepted) {
        int row       = ui->listePatienten->currentRow();
        int realIndex = m_filteredIndices[row];
        manager.getPatients()[realIndex] = dlg.getPatient();
        manager.sortPatients();
        applyFilter();
    }
}

// -------------------- LÖSCHEN --------------------

/**
 * @brief Slot: Löscht den ausgewählten Patienten nach Bestätigung.
 *
 * Zeigt einen Bestätigungsdialog an. Bei Bestätigung wird der Patient
 * anhand des Original-Index aus @c m_filteredIndices aus dem Manager entfernt.
 *
 * @author Mohamed Ilahi
 * @note Seiteneffekt: Entfernt einen Eintrag dauerhaft aus dem PatientManager
 *       und aktualisiert die Listenansicht. Zeigt eine Warnung, falls kein
 *       Patient ausgewählt ist.
 */
void MainWindow::on_pushButtonDelete_clicked()
{
    int row = ui->listePatienten->currentRow();
    if (row < 0 || row >= static_cast<int>(m_filteredIndices.size())) {
        QMessageBox::warning(this, "Hinweis", "Bitte einen Patienten auswählen!");
        return;
    }
    QMessageBox msgBox;
    msgBox.setWindowTitle("Patient löschen");
    msgBox.setText("Soll dieser Patient wirklich gelöscht werden?");
    msgBox.setWindowIcon(style()->standardIcon(QStyle::SP_TrashIcon));
    QPushButton *btnNein = msgBox.addButton("  Abbrechen", QMessageBox::NoRole);
    btnNein->setIcon(style()->standardIcon(QStyle::SP_DialogCancelButton));
    QPushButton *btnJa = msgBox.addButton("  Löschen", QMessageBox::YesRole);
    btnJa->setIcon(style()->standardIcon(QStyle::SP_TrashIcon));
    msgBox.exec();
    if (msgBox.clickedButton() == btnNein) return;

    auto &patients = manager.getPatients();
    patients.erase(patients.begin() + m_filteredIndices[row]);
    manager.sortPatients();
    applyFilter();
}

// -------------------- AUSWAHL AUFHEBEN --------------------

/**
 * @brief Slot: Hebt die aktuelle Auswahl in der Patientenliste auf.
 *
 * Entfernt die Markierung aller Listeneinträge und setzt die
 * aktuelle Zeile auf -1 (keine Auswahl).
 *
 * @author Mohamed Ilahi
 * @note Seiteneffekt: Setzt @c currentRow der ListWidget auf -1.
 */
void MainWindow::on_pushButtonClearSelection_clicked()
{
    ui->listePatienten->clearSelection();
    ui->listePatienten->setCurrentRow(-1);
}
