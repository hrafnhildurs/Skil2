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
    void searchComp();
    void deletePerson();
    void deleteComputer();
    void deleteRelation();
    void computerAsInserted();
    void computerSortAsc();
    void computerSortDesc();
    void computerSortYear();
    void computerSortMenu();
    char computerSortSwitch();
    void addComputer();
    void inputMenu();
    char inputSwitch();
    void viewMenu();
    char viewSwitch();
    void deleteMenu();
    char deleteSwitch();
    void searchMenu();
    char searchSwitch();
    void cDatabaseHeader();
    void cSearchHeader();
    void idDatabaseHeader();
    void idcDatabaseHeader();
    void relationsHeader();
    void relation();
    void addRelations();
    void writeOutPersonVector(vector<person> person);
    void writeOutPersonVectorId(vector<person>);
    void writeOutComVector(vector<computer> computer);
    void writeOutComVectorId(vector<computer>);
    void writeOutRelations(vector<relations> relation);
    int choosePerson();
    int chooseComputer();
};

#endif // INTERFACE_H
