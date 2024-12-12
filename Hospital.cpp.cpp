#include "Hospital.h"
#include <iostream>
using namespace std;

void Hospital::addPerson(shared_ptr<Person> person) {
    people.push_back(person);
}

void Hospital::displayAll() {
    cout << "\nHospital Records:\n";
    for (const auto& person : people) {
        person->displayDetails();
    }
}
