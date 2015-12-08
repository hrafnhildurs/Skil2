#ifndef RELATIONS_H
#define RELATIONS_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class relations
{
protected:
    string rcname;
    string rpname;
    int rcid;
    int rpid;
    int rid;
public:
    relations();
    relations(int &cid, int &pid);
    string returnPname();
    string returnCname();
    int returnCid();
    int returnPid();
    int returnRid();

    void addToRelations(int cid, int pid);
    void addNamesToRelations(int id, string c, string p);

};

#endif // RELATIONS_H
