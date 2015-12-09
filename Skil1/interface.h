#ifndef INTERFACE_H
#define INTERFACE_H
#include "manager.h"
using namespace std;

/* Interface class handles UI for this program calling manager class
 * that fetches informations from the database class and delivers to
 * be displayed on screen.
*/

class Interface
{
public:
    void start();
private:
    Manager manager;

    // Call and display various data on persons in database
    void addPerson();
    void sortMenu();
    char sortSwitch();
    void sortAsc();
    void sortDes();
    void sortBirthYearAsc();
    void asInserted();

    // Search function
    void search();
    void searchComp();

    // Delete function
    void deletePerson();
    void deleteComputer();
    void deleteRelation();

    // Call and display various data on computers in database
    void addComputer();
    void computerAsInserted();
    void computerSortAsc();
    void computerSortDesc();
    void computerSortYear();
    void computerSortMenu();
    char computerSortSwitch();

    // Display of various menus in the program
    char indexSwitch();
    void inputMenu();
    char inputSwitch();
    void viewMenu();
    char viewSwitch();
    void deleteMenu();
    char deleteSwitch();
    void searchMenu();
    char searchSwitch();

    // Headers for various lists to display
    void databaseHeader();
    void searchHeader();
    void cDatabaseHeader();
    void cSearchHeader();
    void idDatabaseHeader();
    void idcDatabaseHeader();
    void relationsHeader();

    // Relations function
    void relation();
    void addRelations();
    int choosePerson();
    int chooseComputer();

    // Functions to write out various data collected into vectors from the database
    void writeOutPersonVector(vector<person> person);
    void writeOutPersonVectorId(vector<person>);
    void writeOutComVector(vector<computer> computer);
    void writeOutComVectorId(vector<computer>);
    void writeOutRelations(vector<relations> relation);
};

#endif // INTERFACE_H
