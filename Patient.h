#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"

class Patient : public Person {
private:
    string ailment;
    int doctorID;

public:
    Patient(string n, int a, string ail, int docID);
    void displayDetails() override;
};

#endif // PATIENT_H
