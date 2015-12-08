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

relations::relations(int& cid, int &pid) {
    rcid = cid;
    rpid = pid;
}

void relations::addToRelations(int cid, int pid) {
    this->rcid = cid;
    this->rpid = pid;
}

int relations::returnCid() {
    return rcid;
}

int relations::returnPid() {
    return rpid;
}

string relations::returnPname() {
    return rpname;
}

string relations::returnCname() {
    return rcname;
}
