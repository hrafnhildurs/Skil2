#include <iostream>
#include <iomanip>
#include "person.h"
#include <string>
#include <time.h>
#include <ctime>
#include <limits>
#include <QtSql>

using namespace std;

person::person()
{
   name = "";
   sex = "";
   birth_year = 0;
   death_year = 0;
}
person::person(string& n, string& s, int& b, int& d){
    name = n;
    sex = s;
    birth_year = b;
    death_year = d;
}
person::person(string& n, string& s, int& b) {
    name = n;
    sex = s;
    birth_year = b;
}

void person::addToPerson(int id, string n, string s, int b, int d) {
    this->id = id;
    this->name = n;
    this->sex = s;
    this->birth_year = b;
    this->death_year = d;
}

int person::returnId() {
    return id;
}

string person::returnName() {
    return name;
}

string person::returnSex() {
    return sex;
}

int person::returnBirthYear() {
    return birth_year;
}

int person::returnDeathYear() {
    return death_year;
}
