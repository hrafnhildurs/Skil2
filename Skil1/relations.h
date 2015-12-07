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
public:
    relations();
    relations(string &p, string &c);
    string returnPname();
    string returnCname();

    friend istream &operator >> (istream& ins, relations& a);
    void addToRelations(string c, string p);
};

#endif // RELATIONS_H
