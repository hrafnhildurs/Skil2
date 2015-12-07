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

void person::addToPerson(string n, string s, int b, int d) {
    this->name = n;
    this->sex = s;
    this->birth_year = b;
    this->death_year = d;
}

string person::returnName() {
    return name;
}

string person::returnSex() {
    return sex;
}

int person::returnBirthYear() {
    return birth_year;
}

int person::returnDeathYear() {
    return death_year;
}

//istream &operator >> (istream& ins, person& a) {

//    QString dblocation = "C:\\Users\\Einir\\Documents\\Verk1\\Vika2\\Skil2\\programmers.sqlite";
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName(dblocation);
//    bool db_ok = db.open();

//    if(db_ok)
//        cout << "Connection established" << endl;
//    else
//    {
//        cout << "Connection failed" << endl;
//        //return 1;
//    }
//    char ans;
//    cout << "Is the person alive? (y/n) ";
//    cin >> ans;

//    string name = a.name;
//    string sex = a.sex;
//    int born = a.birth_year;
//    int died = a.death_year;
//    if(ans == 'y')
//    {
//        cout << "Name: ";
//        ins >> ws;
//        getline(ins, name);
//        cout << "Sex: ";
//        getline(ins, sex);
//        cout << "Birth Year: ";
//        ins >> born;

//        QString qname(name.c_str());
//        QString qsex(sex.c_str());

//        QSqlQuery query;

//        query.prepare("INSERT INTO programmers VALUES(NULL, ?, ?, ?, NULL)");
//        query.addBindValue(qname);
//        query.addBindValue(qsex);
//        query.addBindValue(born);
//        query.exec();
//       }

//    else if(ans ==  'n')
//    {
//        cout << "Name: ";
//        ins >> ws;
//        getline(ins, name);
//        cout << "Sex: ";
//        getline(ins, sex);
//        cout << "Birth Year: ";
//        ins >> born;
//        cout << "Death Year: ";
//        ins >> died;

//        QString qname(name.c_str());
//        QString qsex(sex.c_str());

//        QSqlQuery query;

//        query.prepare("INSERT INTO programmers VALUES(NULL, ?, ?, ?, ?)");
//        query.addBindValue(qname);
//        query.addBindValue(qsex);
//        query.addBindValue(born);
//        query.addBindValue(died);
//        query.exec();
//    }
//    /*outFile.open("out.txt", ofstream::app);
//    if(outFile.fail())
//    {
//        cout << "   outFile opening failed!!" << endl;
//    }



//    outFile << setw(a.name.length()) << a.name << setw(14 + (25 - a.name.length())) << a.sex << setw(9) << a.birth_year << endl;*/

//    db.close();

//    return ins;
//}
