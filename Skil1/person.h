#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


class person
{
protected:
    int id;
    string name;
    string sex;
    int birth_year;
    int death_year;
public:
    person();
    person(string& n, string& s, int& b, int& d);
    person(string& n, string& s, int& b);

    int returnId();
    string returnName();
    string returnSex();
    int returnBirthYear();
    int returnDeathYear();
    void addToPerson(int id, string n, string s, int b, int d);

    friend istream &operator >> (istream& ins, person& a);
};

#endif // PERSON_H
