#ifndef MANAGER_H
#define MANAGER_H
#include "database.h"

class Manager
{
public:
    Manager();
    void addPersonAlive(string n, string s, int b);
    void addPersonDead(string n, string s, int b, int d);
    vector<person> asInserted();
    vector<person> alphabeticSortAsc();
    vector<person> alphabeticSortDes();
    vector<person> birthYearSort();

    void deleteName(string name);
    vector<person> search(string searchWord);

    void addComputer(string cn, int cy, string ct, string cb);
    vector<computer> computerSortAsc();
    vector<computer> computerSortDesc();
    vector<computer> computerSortYear();

private:
    Database db;
};

#endif // MANAGER_H
