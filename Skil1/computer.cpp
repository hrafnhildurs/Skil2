#include <iostream>
#include <iomanip>
#include "computer.h"
#include <string>
#include <QtSql>

using namespace std;

computer::computer()
{
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

istream &operator >> (istream& ins, computer& b) {

    QString dblocation = "C:\\Users\\hivSteini\\Desktop\\Verklegt1\\Verklegt-namskeid-1\\Skil2\\Skil1\\persons.sqlite";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dblocation);
    bool db_ok = db.open();

    if(db_ok)
    {
        cout << "connection ok..." << endl;
    }
    else
        {
        cout << "Connection failed" << endl;
        //return 1;
    }

    string cname = b.cname;
    int cyear = b.cyear;
    string ctype = b.ctype;
    string cbuilt = b.cbuilt;

        cout << "Name: ";
        ins >> ws;
        getline(ins, cname);
        cout << "Year built: ";
        ins >> cyear;
        cout << "Type: ";
        ins >> ctype;
        char ans;
        cout << "was it made ?(y/n): ";
        cin >> ans;
        if(ans == 'y')
        {
            cbuilt = "yes";
        }
        else
        {
            cbuilt = "no";
        }


    QString qcname(cname.c_str());
    QString qctype(ctype.c_str());
    QString qcbuilt(cbuilt.c_str());

    QSqlQuery query;

    query.prepare("INSERT INTO computers VALUES(NULL,?, ?, ?, ?)");
    query.addBindValue(qcname);
    query.addBindValue(cyear);
    query.addBindValue(qctype);
    query.addBindValue(qcbuilt);
    query.exec();

    db.close();

    return ins;
}
