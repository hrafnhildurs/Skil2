#include <iostream>
#include <iomanip>
#include "computer.h"
#include <string>
#include <QtSql>

using namespace std;

computer::computer() {
    id = 0;
   cname = "";
   cyear = 0;
   ctype = "";
   cbuilt = "";
}

computer::computer(string& cn, int& cy, string& ct, string& cb){
    cname = cn;
    cyear = cy;
    ctype = ct;
    cbuilt = cb;
}

void computer::addToComputer(int id, string cn, int cy, string ct, string cb) {
    this->id = id;
    this->cname = cn;
    this->cyear = cy;
    this->ctype = ct;
    this->cbuilt = cb;
}

int computer::returnId(){
    return id;
}

string computer::returnComName() {
    return cname;
}

int computer::returnComYear() {
    return cyear;
}

string computer::returnComType() {
    return ctype;
}

string computer::returnComBuilt() {
    return cbuilt;
}
