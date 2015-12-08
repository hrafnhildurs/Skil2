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
    relations(int &cid, string &p, int pid, string &c);
    string returnPname();
    string returnCname();
    int returnCid();
    int returnPid();

    friend istream &operator >> (istream& ins, relations& a);
    void addToRelations(int cid, string c, int pid, string p);

};

#endif // RELATIONS_H
