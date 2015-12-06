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
};

#endif // INTERFACE_H
