#ifndef COMPUTER
#define COMPUTER
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


class computer
{
protected:
    string cname;
    int cyear;
    string ctype;
    string cbuilt;
public:
    computer();
    computer(string& cn, int& cy, string& ct, string& cb);
    friend istream &operator >> (istream& ins, computer& b);
};

#endif // COMPUTER

