#include "manager.h"

Manager::Manager() { }

// Calls addPersonAlive() function in database class
void Manager::addPersonAlive(string n, string s, int b) {
    db.addPersonAlive(n, s, b);
}
// Calls addPersonDead() function in database class
void Manager::addPersonDead(string n, string s, int b, int d) {
    db.addPersonDead(n, s, b, d);
}

void Manager::addComputer(string cn, int cy, string ct, string cb) {
    db.addComputer(cn, cy, ct, cb);
}

// Prints the list ordered by time inserted
vector<person> Manager::asInserted() {
    return db.pSortAsInserted();
}

// Ascending sorting function
vector<person> Manager::alphabeticSortAsc() {
    return db.pSortAlphAsc();
}

// Descending sorting function
vector<person> Manager::alphabeticSortDes() {
    return db.pSortAlphDes();
}

vector<person> Manager::birthYearSort() {
    return db.pSortByBirthYear();
}

// Search function
vector<person> Manager::search(string searchWord) {
    return db.search(searchWord);
}

// Delete name from database
void Manager::deleteName(string name){
    db.deleteName(name);
}
// Delete computer from database
void Manager::deleteComputer(string name){
    db.deleteComputer(name);
}

vector<computer> Manager::computerSortAsc() {
    return db.cSortAsc();
}
vector<computer> Manager::computerSortDesc() {
    return db.cSortDesc();
}
vector<computer> Manager::computerSortYear() {
    return db.cSortYear();
}
