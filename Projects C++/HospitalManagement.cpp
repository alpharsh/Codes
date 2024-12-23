#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Base Class for Person
class Person {
protected:
    string name;
    int age;
    string gender;
public:
    void inputPersonDetails() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender (M/F): ";
        cin >> gender;
    }

    void displayPersonDetails() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

// Derived Class for Patient
class Patient : public Person {
    int patientID;
    string disease;
public:
    void inputPatientDetails() {
        cout << "\n--- Input Patient Details ---\n";
        inputPersonDetails();
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cout << "Enter Disease: ";
        cin.ignore();
        getline(cin, disease);
    }

    void displayPatientDetails() const {
        cout << "\n--- Patient Details ---\n";
        displayPersonDetails();
        cout << "Patient ID: " << patientID << endl;
        cout << "Disease: " << disease << endl;
    }

    int getPatientID() const {
        return patientID;
    }
};

// Derived Class for Doctor
class Doctor : public Person {
    int doctorID;
    string specialization;
public:
    void inputDoctorDetails() {
        cout << "\n--- Input Doctor Details ---\n";
        inputPersonDetails();
        cout << "Enter Doctor ID: ";
        cin >> doctorID;
        cout << "Enter Specialization: ";
        cin.ignore();
        getline(cin, specialization);
    }

    void displayDoctorDetails() const {
        cout << "\n--- Doctor Details ---\n";
        displayPersonDetails();
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Specialization: " << specialization << endl;
    }

    int getDoctorID() const {
        return doctorID;
    }
};

// Class for Hospital Management System
class HospitalManagementSystem {
    vector<Patient> patients;
    vector<Doctor> doctors;

public:
    void addPatient() {
        Patient p;
        p.inputPatientDetails();
        patients.push_back(p);
        cout << "Patient added successfully.\n";
    }

    void addDoctor() {
        Doctor d;
        d.inputDoctorDetails();
        doctors.push_back(d);
        cout << "Doctor added successfully.\n";
    }

    void viewPatients() const {
        if (patients.empty()) {
            cout << "No patients available.\n";
            return;
        }
        for (const auto &p : patients) {
            p.displayPatientDetails();
        }
    }

    void viewDoctors() const {
        if (doctors.empty()) {
            cout << "No doctors available.\n";
            return;
        }
        for (const auto &d : doctors) {
            d.displayDoctorDetails();
        }
    }

    void searchPatient() const {
        int id;
        cout << "Enter Patient ID to search: ";
        cin >> id;
        for (const auto &p : patients) {
            if (p.getPatientID() == id) {
                p.displayPatientDetails();
                return;
            }
        }
        cout << "Patient with ID " << id << " not found.\n";
    }

    void searchDoctor() const {
        int id;
        cout << "Enter Doctor ID to search: ";
        cin >> id;
        for (const auto &d : doctors) {
            if (d.getDoctorID() == id) {
                d.displayDoctorDetails();
                return;
            }
        }
        cout << "Doctor with ID " << id << " not found.\n";
    }
};

// Main Function
int main() {
    HospitalManagementSystem hms;
    int choice;

    do {
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. View All Patients\n";
        cout << "4. View All Doctors\n";
        cout << "5. Search Patient by ID\n";
        cout << "6. Search Doctor by ID\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hms.addPatient();
                break;
            case 2:
                hms.addDoctor();
                break;
            case 3:
                hms.viewPatients();
                break;
            case 4:
                hms.viewDoctors();
                break;
            case 5:
                hms.searchPatient();
                break;
            case 6:
                hms.searchDoctor();
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
