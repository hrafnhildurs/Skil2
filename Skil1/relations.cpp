#include "relations.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <QtSql>

using namespace std;

relations::relations ()
{
    rcid = 0;
    rcname = "";
    rpid = 0;
    rpname = "";
}

relations::relations(int& cid, string& c, int pid, string& p)
{
    rcid = cid;
    rcname = c;
    rpid = pid;
    rpname = p;
}
void relations::addToRelations(int cid, string c,int pid, string p) {
    this->rcid = cid;
    this->rcname = c;
    this->rpid = pid;
    this->rpname = p;
}
string relations::returnCname() {
    return rcname;
}
string relations::returnPname() {
    return rpname;
}
int relations::returnCid() {
    return rcid;
}

int relations::returnPid() {
    return rpid;
}
