#include "relations.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <QtSql>

using namespace std;

relations::relations ()
{
    rcname = "";
    rpname = "";
}

relations::relations(string& c, string& p)
{
    rcname = c;
    rpname = p;
}
void relations::addToRelations(string c, string p) {
    this->rcname = c;
    this->rpname = p;
}
string relations::returnCname() {
    return rcname;
}
string relations::returnPname() {
    return rpname;
}
