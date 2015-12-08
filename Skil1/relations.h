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
public:
    relations();
    relations(int &cid, int &pid);
    string returnPname();
    string returnCname();
    int returnCid();
    int returnPid();

    void addToRelations(int cid, int pid);

};

#endif // RELATIONS_H
