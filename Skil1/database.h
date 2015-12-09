#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <locale>
#include <stdlib.h>
#include "person.h"
#include "computer.h"
#include "relations.h"
#include <QtSql>

/* Database class handles all queries made to the SQL database by the
 * manager class.
*/

class Database
{
public:
    // Constructor & Destructor
    Database();
    ~Database();

    // Adding functions
    void addPersonAlive(string n, string s, int b);
    void addPersonDead(string n, string s, int b, int d);
    void addComputer(string cn, int cy, string ct, string cb);
    void addRelations(int pid, int cid);
    void addNamesRelations(int id, string p, string c);

    // Helper function to see if connection to database is ok.
    bool connectionOk();

    // Person vectors with various sorting preferences from database
    vector<person> pSortAsInserted();
    vector<person> pSortAlphAsc();
    vector<person> pSortAlphDes();
    vector<person> pSortByBirthYear();
    vector<person> search(string searchWord);

    // Computer vectors with verious sorting preferences from database
    vector<computer> cAsInserted();
    vector<computer> cSortAsc();
    vector<computer> cSortDesc();
    vector<computer> cSortYear();
    vector<computer> searchComp(string searchWord);

    // Vector containing relations between computers and computer scientists
    vector<relations> relation();

    // Helper delete functions
    void deleteName(string name);
    void deleteComputer(string name);
    void deleteRelation(int id);
private:
    // Handles queries from manager class to obtain data from database
    // and writes corresponding data into a vector of object asked for
    vector<person> writeToVector(QSqlQuery query);
    vector<computer> writeComToVector(QSqlQuery query);
    vector<relations> writeOutComAndPersonVector(QSqlQuery query);
    vector<relations> writeOutRelations(QSqlQuery query);

    // Handles deletion from the database
    void deleteName(string name, bool db_ok);
    void deleteComputer(string name, bool db_ok);
    void deleteRelation(int id, bool db_ok);

    // Private variables/objects owned by database class
    bool db_ok;
    person pers;
    computer com;
    relations rel;
    QSqlDatabase db;
    const QString DB_LOCATION = "C:\\Users\\Einir\\Documents\\Verk1\\Vika2\\Skil2\\programmers2.sqlite";
};

#endif // DATABASE_H
