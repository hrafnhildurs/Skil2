#ifndef INTERFACE_H
#define INTERFACE_H
#include "manager.h"
using namespace std;

class Interface
{
public:
    void start();
private:
    Manager manager;
    char indexSwitch();
    void addPerson();
    void sortMenu();
    char sortSwitch();
    void sortAsc();
    void sortDes();
    void sortBirthYearAsc();
    void asInserted();
    void databaseHeader();
    void searchHeader();
    void search();
    void deletePerson();
    void computerSortAsc();
    void computerSortDesc();
    void computerSortYear();
    void computerSortMenu();
    char computerSortSwitch();
    void addComputer();
    void writeOutPersonVector(vector<person> person);
    void writeOutComVector(vector<computer> computer);
};

#endif // INTERFACE_H
