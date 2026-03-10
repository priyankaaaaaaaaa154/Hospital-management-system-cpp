#include <iostream>
#include <string>

const int MAX_PATIENTS = 100;
const int MAX_STAFF = 50;

using namespace std;

// Class representing a Patient
class Patient {
public:
    string name;
    int age;
    string condition;

    Patient() : age(0) {}  // Default constructor for array initialization
};

// Class representing a Staff member
class Staff {
public:
    string name;
    string role;

    Staff() {}  // Default constructor for array initialization
};

// Class representing a Hospital
class Hospital {
private:
    Patient patients[MAX_PATIENTS];
    Staff staff[MAX_STAFF];
    int patientCount;
    int staffCount;

public:
    Hospital() : patientCount(0), staffCount(0) {}

    // Function to admit a new patient to the hospital
    void admitPatient(const string& name, int age, const string& condition) {
        if (patientCount < MAX_PATIENTS) {
            patients[patientCount].name = name;
            patients[patientCount].age = age;
            patients[patientCount].condition = condition;
            patientCount++;
        } else {
            cout << "\nHospital is full. Cannot admit more patients." << endl;
        }
    }

    // Function to discharge a patient from the hospital
    void dischargePatient(const string& name) {
        for (int i = 0; i < patientCount; ++i) {
            if (patients[i].name == name) {
                // Move the last patient to the discharged patient's position
                patients[i] = patients[patientCount - 1];
                patientCount--;
                cout<<"\nDISCHARGED\n";
                break;
            }
        }
    }

    // Function to update the condition of a patient
    void updatePatientCondition(const string& name, const string& newCondition) {
        for (int i = 0; i < patientCount; ++i) {
            if (patients[i].name == name) {
                patients[i].condition = newCondition;
                break;
            }
        }
    }

    // Function to display details of a specific patient
    void displayPatientDetails(const string& name) const {
        for (int i = 0; i < patientCount; ++i) {
            if (patients[i].name == name) {
                cout << "Patient Details:\n";
                cout << "Name: " << patients[i].name << "\n";
                cout << "Age: " << patients[i].age << "\n";
                cout << "Condition: " << patients[i].condition << "\n";
                return;
            }
        }
        cout << "Patient not found.\n";
    }

    // Function to print the count of current patients
    void printPatientCount() const {
        cout << "Number of patients: " << patientCount << endl;
    }

    // Function to hire new staff for the hospital
    void hireStaff(const string& name, const string& role) {
        if (staffCount < MAX_STAFF) {
            staff[staffCount].name = name;
            staff[staffCount].role = role;
            staffCount++;
            cout << "Staff hired successfully.\n";
        } else {
            cout << "Maximum staff limit reached. Cannot hire more staff.\n";
        }
    }

    // Function to print the details of available staff and make a selection
    void printStaffSelection() const {
        // ... (code for printing staff details and making a selection)
    }
};

// Main function where the program execution begins
int main() {
    Hospital hospital;
    int choice;

    // Main menu loop
    do {
        // Displaying menu options
        cout << "1. Admit Patient\n";
        cout << "2. Discharge Patient\n";
        cout << "3. Update Patient Condition\n";
        cout << "4. Display Patient Details\n";
        cout << "5. Print Patient Count\n";
        cout << "6. Hire Staff\n";
        cout << "7. Display Staff Details\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";

        // Reading user choice
        cin >> choice;

        // Switch statement to handle different menu options
        switch (choice) {
            // ... (cases for different options)
             case 1: {
                string name, condition;
                int age;
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter patient age: ";
                cin >> age;
                cout << "Enter patient condition: ";
                cin >> condition;
                hospital.admitPatient(name, age, condition);
                break;
            }
            case 2: {
                string name;
                cout << "Enter patient name to discharge: ";
                cin >> name;
                hospital.dischargePatient(name);
                break;
            }
            case 3: {
                string name, newCondition;
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter new condition: ";
                cin >> newCondition;
                hospital.updatePatientCondition(name, newCondition);
                break;
            }
            case 4: {
                string name;
                cout << "Enter patient name: ";
                cin >> name;
                hospital.displayPatientDetails(name);
                break;
            }
            case 5:
                hospital.printPatientCount();
                break;
            case 6: {
                string name, role;
                cout << "Enter staff name: ";
                cin >> name;
                cout << "Enter staff role: ";
                cin >> role;
                hospital.hireStaff(name, role);
                break;
            }
            case 7:
                hospital.printStaffSelection();
                break;
            case 8:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }


    } while (choice != 8);  // Exit loop when the user chooses to exit

    return 0;
}
