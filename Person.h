#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void displayDetails() = 0; // Pure virtual function
    virtual ~Person() {}
};

#endif // PERSON_H
