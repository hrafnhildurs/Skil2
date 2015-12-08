#ifndef COMPUTER
#define COMPUTER
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


class computer
{
protected:
    int id;
    string cname;
    int cyear;
    string ctype;
    string cbuilt;

public:
    computer();
    computer(string& cn, int& cy, string& ct, string& cb);
    int returnId();
    string returnComName();
    int returnComYear();
    string returnComType();
    string returnComBuilt();

    friend istream &operator >> (istream& ins, computer& b);
    void addToComputer(int id, string cn, int cy, string ct, string cb);
};

#endif // COMPUTER

