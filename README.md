# Patient Management System C++ & Qt

A Qt-based desktop application for managing patient records through a graphical user interface. The project was developed using **C++ and Qt** and demonstrates object-oriented programming, data management, input validation, and GUI development.

## Features

- **Add Patients:** Create new patient records with personal information.
- **Edit Patient Records:** Update existing patient information.
- **Delete Patients:** Remove records with a confirmation dialog.
- **Patient Details:** View the complete information of a selected patient.
- **Real-Time Search:** Filter the patient list by first name, last name, and optionally date of birth.
- **Automatic Sorting:** Sort patient records by last name, first name, and date of birth.
- **Input Validation:** Validate required fields and restrict phone number input to digits, `+`, and spaces.
- **Data Persistence:** Automatically load and save patient records using a text file.
- **Graphical User Interface:** Use separate dialogs for editing and viewing patient information.

## Technologies

- C++
- Qt Framework
- Qt Widgets
- Object-Oriented Programming

## How It Works

The application is organized into several classes:

- **Patient:** Represents a patient record and stores attributes such as name, title, address, phone number, date of birth, and gender.
- **PatientManager:** Manages the patient list, sorting, and loading and saving data.
- **MainWindow:** Provides the main interface, patient list, search functionality, and action buttons.
- **PatientDialog:** Allows users to add and edit patient records, including input validation.
- **PatientDetailsDialog:** Displays the complete information of a selected patient.

## Data Storage

Patient records are loaded from `patients.txt` when the application starts and saved automatically when it closes. The records are stored in a semicolon-separated text format.

## Documentation

For a detailed explanation of the program structure, features, filtering, sorting, data persistence, and input validation, see the full documentation:

[**Read the full documentation (PDF)**](./Funktionsweise%20der%20Patientenverwaltung.pdf)

## Author

Developed as a C++ and Qt programming project.
