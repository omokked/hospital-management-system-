#include "Patient.h"
#include <iostream>
using namespace std;

Patient::Patient(string n, int a, string ail, int docID)
    : Person(n, a), ailment(ail), doctorID(docID) {}

void Patient::displayDetails() {
    cout << "Patient - Name: " << name << ", Age: " << age
         << ", Ailment: " << ailment
         << ", Assigned Doctor ID: " << doctorID << endl;
}
