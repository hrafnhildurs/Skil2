#include <iostream>
#include <iomanip>
#include "person.h"
#include <string>
#include <time.h>
#include <ctime>
#include <limits>
#include <QtSql>

using namespace std;

person::person()
{
   name = "";
   sex = "";
   birth_year = 0;
   death_year = 0;
}
person::person(string& n, string& s, int& b, int& d){
    name = n;
    sex = s;
    birth_year = b;
    death_year = d;
}
person::person(string& n, string& s, int& b) {
    name = n;
    sex = s;
    birth_year = b;
}

istream &operator >> (istream& ins, person& a) {

    ofstream outFile;

    QString dblocation = "C:\\Users\\IceVinking\\Documents\\Skole\\githubSkole\\Database\\persons.sqlite";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dblocation);
    bool db_ok = db.open();

    if(db_ok)
        cout << "Connection established" << endl;
    else
    {
        cout << "Connection failed" << endl;
        //return 1;
    }

    string name = a.name;
    string sex = a.sex;
    int born = a.birth_year;
    int died = a.death_year;

    cout << "Name: ";
    ins >> ws;
    getline(ins, name);
    cout << "Sex: ";
    getline(ins, sex);
    cout << "Birth Year: ";
    ins >> born;
    cout << "Death Year: ";
    ins >> died;

    QString qname(name.c_str());
    QString qsex(sex.c_str());

    QSqlQuery query;

    query.prepare("INSERT INTO programers VALUES(NULL, ?, ?, ?, ?)");
    query.addBindValue(qname);
    query.addBindValue(qsex);
    query.addBindValue(born);
    query.addBindValue(died);
    query.exec();

    /*outFile.open("out.txt", ofstream::app);
    if(outFile.fail())
    {
        cout << "   outFile opening failed!!" << endl;
    }



    outFile << setw(a.name.length()) << a.name << setw(14 + (25 - a.name.length())) << a.sex << setw(9) << a.birth_year << endl;*/

    db.close();

    return ins;
}