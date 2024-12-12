#include "Doctor.h"
#include <iostream>
using namespace std;

Doctor::Doctor(string n, int a, string spec, double sal)
    : Person(n, a), specialization(spec), salary(sal) {}

void Doctor::displayDetails() {
    cout << "Doctor - Name: " << name << ", Age: " << age
         << ", Specialization: " << specialization
         << ", Salary: KSh " << salary << endl;
}
