#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

/*
 * Class that handles everything that has to do with each computer scientist
 * inserted into the database.
*/
class person
{
public:
    // Constructors
    person();
    person(string& n, string& s, int& b, int& d);
    person(string& n, string& s, int& b);

    // Helper functions to access private variable values
    int returnId();
    string returnName();
    string returnSex();
    int returnBirthYear();
    int returnDeathYear();

    // Helper function for relations
    void addToPerson(int id, string n, string s, int b, int d);
private:
    int id;
    string name;
    string sex;
    int birth_year;
    int death_year;
};

#endif // PERSON_H
