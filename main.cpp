#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Struct for Doctor
struct Doctor {
    string name;
    int age;
    string specialization;
    double salary;
};

// Struct for Patient
struct Patient {
    string name;
    int age;
    string ailment;
    int doctorID;
};

// Global vectors to store doctors and patients
vector<Doctor> doctors;
vector<Patient> patients;

// File names for saving data
const string DOCTOR_FILE = "doctors.txt";
const string PATIENT_FILE = "patients.txt";

// Function to save doctors to a file
void saveDoctors() {
    ofstream outFile(DOCTOR_FILE);
    for (const auto& doctor : doctors) {
        outFile << doctor.name << "," << doctor.age << "," << doctor.specialization << "," << doctor.salary << "\n";
    }
    outFile.close();
    cout << "Doctor records saved successfully.\n";
}

// Function to save patients to a file
void savePatients() {
    ofstream outFile(PATIENT_FILE);
    for (const auto& patient : patients) {
        outFile << patient.name << "," << patient.age << "," << patient.ailment << "," << patient.doctorID << "\n";
    }
    outFile.close();
    cout << "Patient records saved successfully.\n";
}

// Function to load doctors from a file
void loadDoctors() {
    ifstream inFile(DOCTOR_FILE);
    if (!inFile) {
        cout << "No saved doctor records found.\n";
        return;
    }

    Doctor doctor;
    while (getline(inFile, doctor.name, ',')) {
        inFile >> doctor.age;
        inFile.ignore();
        getline(inFile, doctor.specialization, ',');
        inFile >> doctor.salary;
        inFile.ignore();
        doctors.push_back(doctor);
    }
    inFile.close();
    cout << "Doctor records loaded successfully.\n";
}

// Function to load patients from a file
void loadPatients() {
    ifstream inFile(PATIENT_FILE);
    if (!inFile) {
        cout << "No saved patient records found.\n";
        return;
    }

    Patient patient;
    while (getline(inFile, patient.name, ',')) {
        inFile >> patient.age;
        inFile.ignore();
        getline(inFile, patient.ailment, ',');
        inFile >> patient.doctorID;
        inFile.ignore();
        patients.push_back(patient);
    }
    inFile.close();
    cout << "Patient records loaded successfully.\n";
}

// Function to add a doctor
void addDoctor() {
    Doctor doctor;
    cout << "Enter Doctor's Name: ";
    cin.ignore();
    getline(cin, doctor.name);
    cout << "Enter Doctor's Age: ";
    cin >> doctor.age;
    cout << "Enter Specialization: ";
    cin.ignore();
    getline(cin, doctor.specialization);
    cout << "Enter Salary: ";
    cin >> doctor.salary;
    doctors.push_back(doctor);
    saveDoctors(); // Automatically save to file
    cout << "Doctor added and saved successfully!\n";
}

// Function to add a patient
void addPatient() {
    if (doctors.empty()) {
        cout << "No doctors available. Add a doctor first.\n";
        return;
    }

    Patient patient;
    cout << "Enter Patient's Name: ";
    cin.ignore();
    getline(cin, patient.name);
    cout << "Enter Patient's Age: ";
    cin >> patient.age;
    cout << "Enter Ailment: ";
    cin.ignore();
    getline(cin, patient.ailment);
    cout << "Enter Assigned Doctor ID (0 to " << doctors.size() - 1 << "): ";
    cin >> patient.doctorID;

    if (patient.doctorID < 0 || patient.doctorID >= doctors.size()) {
        cout << "Invalid Doctor ID. Patient not added.\n";
        return;
    }

    patients.push_back(patient);
    savePatients(); // Automatically save to file
    cout << "Patient added and saved successfully!\n";
}

// Function to display all records
void displayRecords() {
    if (doctors.empty() && patients.empty()) {
        cout << "No records available.\n";
        return;
    }

    cout << "\n--- Hospital Records ---\n";

    if (!doctors.empty()) {
        cout << "\nDoctors:\n";
        for (size_t i = 0; i < doctors.size(); i++) {
            cout << "Doctor ID: " << i << ", Name: " << doctors[i].name
                 << ", Age: " << doctors[i].age << ", Specialization: " << doctors[i].specialization
                 << ", Salary: " << doctors[i].salary << " KSh\n";
        }
    }

    if (!patients.empty()) {
        cout << "\nPatients:\n";
        for (size_t i = 0; i < patients.size(); i++) {
            cout << "Name: " << patients[i].name << ", Age: " << patients[i].age
                 << ", Ailment: " << patients[i].ailment << ", Assigned Doctor ID: " << patients[i].doctorID << "\n";
        }
    }
}

// Main Function
int main() {
    loadDoctors(); // Load previously saved doctor records
    loadPatients(); // Load previously saved patient records

    int choice;

    do {
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Add Doctor\n";
        cout << "2. Add Patient\n";
        cout << "3. Display All Records\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addDoctor();
                break;
            case 2:
                addPatient();
                break;
            case 3:
                displayRecords();
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
