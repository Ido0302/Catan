#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Person{
    private:
    string name;
    int age;

    public:
    Person(string name, int age);
    string getName();
    int getAge();
};



#endif