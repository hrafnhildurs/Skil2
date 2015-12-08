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
void relations::addNamesToRelations(int id, string p, string c) {
    this->rid = id;
    this->rpname = p;
    this->rcname = c;
}

int relations::returnRid() {
    return rid;
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
