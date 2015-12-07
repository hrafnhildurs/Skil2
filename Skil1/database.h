#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <locale>
#include "person.h"
#include "computer.h"
#include <QtSql>

class Database
{
public:
    Database();
    ~Database();
    void addPersonAlive(string n, string s, int b);
    void addPersonDead(string n, string s, int b, int d);
    void addComputer(string cn, int cy, string ct, string cb);
    bool connectionOk();

    vector<person> pSortAsInserted();
    vector<person> pSortAlphAsc();
    vector<person> pSortAlphDes();
    vector<person> pSortByBirthYear();
    vector<person> search(string searchWord);

    vector<computer> cSortAsc();
    vector<computer> cSortDesc();
    vector<computer> cSortYear();
    vector<computer> searchComp(string searchWord);

    void deleteName(string name);
    void deleteComputer(string name);

private:
    vector<person> writeToVector(QSqlQuery query);
    vector<computer> writeComToVector(QSqlQuery query);
    void deleteName(string name, bool db_ok);
    void deleteComputer(string name, bool db_ok);

    bool db_ok;
    person pers;
    computer com;
    QSqlDatabase db;
    const QString DB_LOCATION = "C:\\Users\\IceVinking\\Documents\\Skole\\githubSkole\\Skil2\\programmers.sqlite";
};

#endif // DATABASE_H
