#include "database.h"

Database::Database() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DB_LOCATION);
    db_ok = db.open();

    if(!db_ok)
        cout << "Connection to database failed" << endl;
}

Database::~Database() {
    db.close();
}

bool Database::connectionOk() {
    return db_ok;
}

void Database::addPersonAlive(string n, string s, int b) {
    QString name(n.c_str());
    QString sex(s.c_str());

    QSqlQuery query;
    query.prepare("INSERT INTO programmers VALUES(NULL, ?, ?, ?, NULL)");
    query.addBindValue(name);
    query.addBindValue(sex);
    query.addBindValue(b);
    query.exec();
}

void Database::addPersonDead(string n, string s, int b, int d) {
    QString name(n.c_str());
    QString sex(s.c_str());

    QSqlQuery query;
    query.prepare("INSERT INTO programmers VALUES(NULL, ?, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(sex);
    query.addBindValue(b);
    query.addBindValue(d);
    query.exec();
}

void Database::addComputer(string cn, int cy, string ct, string cb) {
    QString cname(cn.c_str());
    QString ctype(ct.c_str());
    QString cbuilt(cb.c_str());

    QSqlQuery query;

    query.prepare("INSERT INTO computers VALUES(NULL,?, ?, ?, ?)");
    query.addBindValue(cname);
    query.addBindValue(cy);
    query.addBindValue(ctype);
    query.addBindValue(cbuilt);
    query.exec();
}

vector<person> Database::writeToVector(QSqlQuery query) {
    vector<person> tmp;
    while (query.next())
    {
        pers.addToPerson(query.value(1).toString().toStdString(),
                         query.value(2).toString().toStdString(),
                         query.value(3).toInt(),
                         query.value(4).toInt());

        tmp.push_back(pers);
    }
    return tmp;
}

vector<person> Database::pSortAsInserted() {
    QSqlQuery query("SELECT * FROM programmers");
    return writeToVector(query);
}

vector<person> Database::pSortAlphAsc() {
    QSqlQuery query("SELECT * FROM programmers ORDER BY name ASC");
    return writeToVector(query);
}

vector<person> Database::pSortAlphDes() {
    QSqlQuery query("SELECT * FROM programmers ORDER BY name DESC");
    return writeToVector(query);
}

vector<person> Database::pSortByBirthYear() {
    QSqlQuery query("SELECT * FROM programmers ORDER BY birthYear ASC ");
    return writeToVector(query);
}

vector<person> Database::search(string searchWord) {
    QSqlQuery query;
    QString search(searchWord.c_str());
    //if(db_ok) {
        query.prepare("SELECT * FROM programmers WHERE name LIKE '%' || ? || '%' ");
        query.addBindValue(search);
        query.exec();

        return writeToVector(query);
    //}
}

void Database::deleteName(string name) {
    deleteName(name, db_ok);
}
void Database::deleteComputer(string name) {
    deleteComputer(name, db_ok);
}

void Database::deleteName(string name, bool db_ok) {
    if(db_ok) {
        QString nameToDel(name.c_str());

        QSqlQuery query;
        query.prepare("DELETE FROM programmers WHERE name = ?");
        query.addBindValue(nameToDel);
        query.exec();
    }
}
void Database::deleteComputer(string name, bool db_ok) {
    if(db_ok) {
        QString nameToDel(name.c_str());

        QSqlQuery query;
        query.prepare("DELETE FROM computers WHERE name = ?");
        query.addBindValue(nameToDel);
        query.exec();
    }
}

vector<computer> Database::cSortAsc() {
    QSqlQuery query("SELECT * FROM computers ORDER BY name ASC");
    return writeComToVector(query);
}

vector<computer> Database::cSortDesc() {
    QSqlQuery query("SELECT * FROM computers ORDER BY name DESC");
    return writeComToVector(query);
}

vector<computer> Database::cSortYear() {
    QSqlQuery query("SELECT * FROM computers ORDER BY year ASC");
    return writeComToVector(query);
}

vector<computer> Database::writeComToVector(QSqlQuery query) {
    vector<computer> tmp;
    while (query.next())
    {
        com.addToComputer(query.value(1).toString().toStdString(),
                         query.value(2).toInt(),
                         query.value(3).toString().toStdString(),
                         query.value(4).toString().toStdString());

        tmp.push_back(com);
    }
    return tmp;
}
