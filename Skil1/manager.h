#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include "person.h"
#include <QtSql>

class Manager
{
public:
    Manager();
    void addPerson();
    QSqlDatabase readFromFile();
    void alphabeticSortAsc(QSqlDatabase db);
    void alphabeticSortDes(QSqlDatabase db);
    void birthYearSort(QSqlDatabase db);
    void asInserted(QSqlDatabase db);
    void deleteName(const char doc[], vector<string> tempVec);
    string readSearchWord();
    void search(const char doc[], string letters);
    //void DocString (const char doc[], vector<string> stringVec);
private:
    person pers;
};

#endif // MANAGER_H
