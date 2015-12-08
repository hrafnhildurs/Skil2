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
#include "relations.h"
#include <QtSql>

class Database
{
public:
    Database();
    ~Database();
    void addPersonAlive(string n, string s, int b);
    void addPersonDead(string n, string s, int b, int d);
    void addComputer(string cn, int cy, string ct, string cb);
    void addRelations(int pid, int cid);
    bool connectionOk();

    vector<person> pSortAsInserted();
    vector<person> pSortAlphAsc();
    vector<person> pSortAlphDes();
    vector<person> pSortByBirthYear();
    vector<person> search(string searchWord);

    vector<computer> cAsInserted();
    vector<computer> cSortAsc();
    vector<computer> cSortDesc();
    vector<computer> cSortYear();
    vector<computer> searchComp(string searchWord);

    vector<relations> relation();

    void deleteName(string name);
    void deleteComputer(string name);

private:
    vector<person> writeToVector(QSqlQuery query);
    vector<computer> writeComToVector(QSqlQuery query);
    vector<relations> writeOutComAndPersonVector(QSqlQuery query);

    void deleteName(string name, bool db_ok);
    void deleteComputer(string name, bool db_ok);

    bool db_ok;
    person pers;
    computer com;
    relations rel;
    QSqlDatabase db;
    const QString DB_LOCATION = "C:\\Users\\Einir\\Documents\\GitHub\\Skil2\\programmers2.sqlite";
};

#endif // DATABASE_H
