#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"

class Doctor : public Person {
private:
    string specialization;
    double salary;

public:
    Doctor(string n, int a, string spec, double sal);
    void displayDetails() override;
};

#endif // DOCTOR_H
