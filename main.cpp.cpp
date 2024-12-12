#include "Doctor.h"
#include "Patient.h"
#include "Hospital.h"
#include <iostream>
using namespace std;

int main() {
    try {
        Hospital hospital;

        // Add Doctors
        hospital.addPerson(make_shared<Doctor>("Dr. Wanjiru", 40, "Pediatrics", 250000));
        hospital.addPerson(make_shared<Doctor>("Dr. Otieno", 50, "Orthopedics", 300000));

        // Add Patients
        hospital.addPerson(make_shared<Patient>("Mwangi Kimani", 28, "Malaria", 101));
        hospital.addPerson(make_shared<Patient>("Achieng Oloo", 35, "Fracture", 102));

        // Display All Records
        hospital.displayAll();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
