#include <iostream>
#include <stdexcept>
#include <vector>

#include "Person.hpp"

using namespace std;

Person::Person(string name, int age) : name(name),age(age){}; 

string Person::getName()
{
    return this->name;
}

int Person::getAge(){
    return this->age;
}