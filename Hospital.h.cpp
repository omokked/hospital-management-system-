#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Person.h"
#include <vector>
#include <memory>
using namespace std;

class Hospital {
private:
    vector<shared_ptr<Person>> people;

public:
    void addPerson(shared_ptr<Person> person);
    void displayAll();
};

#endif // HOSPITAL_H
