#include "manager.h"

Manager::Manager() {}

// Calls the overloaded cin (>>) operator in Person class to insert into database
void Manager::addPerson() {
    cin >> pers;
}

struct prog
{
    int id;
    string name;
    string sex;
    int birthYear;
    int deathYear;
};


// Helper function that returns a vector from database file
QSqlDatabase Manager::readFromFile() {
    string word;
    prog ramers;
    vector<prog> cnames;

    QString dblocation = "C:\\Users\\Hrafnhildur\\Documents\\Skólinn\\Verklegt namskeid 1\\Vika2\\Skil2\\programmers.sqlite";
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

    db.close();

    return db;
}

// Prints the list ordered by time inserted
void Manager::asInserted(QSqlDatabase db) {
    bool db_ok = db.open();

    if(db_ok)
    {
      QSqlQuery query1("SELECT * FROM programmers");
      while (query1.next())
      {
          //int id = query1.value(0).toInt();
          string name = query1.value(1).toString().toStdString();
          string sex = query1.value(2).toString().toStdString();
          int birthYear = query1.value(3).toInt();
          int deathYear = query1.value(4).toInt();

          cout << name << ", " << sex << ", " << birthYear << ", " << deathYear << endl;
      }
    }

}

// Ascending sorting function
void Manager::alphabeticSortAsc(QSqlDatabase db) {
    bool db_ok = db.open();

    if(db_ok)
    {
      QSqlQuery query1("SELECT * FROM programmers ORDER BY name ASC");
      while (query1.next())
      {
          //int id = query1.value(0).toInt();
          string name = query1.value(1).toString().toStdString();
          string sex = query1.value(2).toString().toStdString();
          int birthYear = query1.value(3).toInt();
          int deathYear = query1.value(4).toInt();

          cout << name << ", " << sex << ", " << birthYear << ", " << deathYear << endl;
      }
    }
}

// Descending sorting function
void Manager::alphabeticSortDes(QSqlDatabase db) {
    bool db_ok = db.open();

    if(db_ok)
    {
      QSqlQuery query1("SELECT * FROM programmers ORDER BY name DESC");
      while (query1.next())
      {
          //int id = query1.value(0).toInt();
          string name = query1.value(1).toString().toStdString();
          string sex = query1.value(2).toString().toStdString();
          int birthYear = query1.value(3).toInt();
          int deathYear = query1.value(4).toInt();

          cout << name << ", " << sex << ", " << birthYear << ", " << deathYear << endl;
      }
    }
}

void Manager::birthYearSort(QSqlDatabase db) {
    bool db_ok = db.open();

    if(db_ok)
    {
      QSqlQuery query1("SELECT * FROM programmers ORDER BY birthYear ASC ");
      while (query1.next())
      {
          //int id = query1.value(0).toInt();
          string name = query1.value(1).toString().toStdString();
          string sex = query1.value(2).toString().toStdString();
          int birthYear = query1.value(3).toInt();
          int deathYear = query1.value(4).toInt();

          cout << name << ", " << sex << ", " << birthYear << ", " << deathYear << endl;
      }
    }
}

// Helper function that reads search input from user
string Manager::readSearchWord() {
    string searchWord;
    cout << setw(52) << "Enter search word: ";
    cin >> searchWord;
    return searchWord;
}

// Search function
void Manager::search(QSqlDatabase db, string searchWord) {
    bool db_ok = db.open();
    QSqlQuery query1;
    QString qname(searchWord.c_str());
    if(db_ok)
    {

      query1.prepare("SELECT * FROM programmers WHERE name LIKE '%' || ? || '%' ");
      query1.addBindValue(qname);
      query1.exec();

      while (query1.next())
      {
          //int id = query1.value(0).toInt();
          string name = query1.value(1).toString().toStdString();
          string sex = query1.value(2).toString().toStdString();
          int birthYear = query1.value(3).toInt();
          int deathYear = query1.value(4).toInt();

          cout << name << ", " << sex << ", " << birthYear << ", " << deathYear << endl;
      }
    }
}

// Delete name from database
void Manager::deleteName(QSqlDatabase db){
    bool db_ok = db.open();
    QSqlQuery query1;
    string del;

    cout << "Enter a full name of the person you want to delete: ";
    cin >> ws;
    getline(cin,del);

    QString qname(del.c_str());
    if(db_ok)
    {

      query1.prepare("DELETE FROM programmers WHERE name = ?");
      query1.addBindValue(qname);
      query1.exec();

      while (query1.next())
      {
          //int id = query1.value(0).toInt();
          string name = query1.value(1).toString().toStdString();
          string sex = query1.value(2).toString().toStdString();
          int birthYear = query1.value(3).toInt();
          int deathYear = query1.value(4).toInt();

          cout << name << ", " << sex << ", " << birthYear << ", " << deathYear << endl;
      }
    }

}
void Manager::computerSortAsc(QSqlDatabase db) {
    bool db_ok = db.open();

    if(db_ok)
    {
      QSqlQuery query1("SELECT * FROM computers ORDER BY name ASC");
      while (query1.next())
      {
          //int id = query1.value(0).toInt();
          string name = query1.value(1).toString().toStdString();
          string type = query1.value(2).toString().toStdString();
          int year = query1.value(3).toInt();
          string built = query1.value(4).toString().toStdString();

          cout << name << ", " << type << ", " << year << ", " << built << endl;
      }
    }
}
void Manager::computerSortDesc(QSqlDatabase db) {
    bool db_ok = db.open();

    if(db_ok)
    {
      QSqlQuery query1("SELECT * FROM computers ORDER BY name DESC");
      while (query1.next())
      {
          //int id = query1.value(0).toInt();
          string name = query1.value(1).toString().toStdString();
          string type = query1.value(2).toString().toStdString();
          int year = query1.value(3).toInt();
          string built = query1.value(4).toString().toStdString();

          cout << name << ", " << type << ", " << year << ", " << built << endl;
      }
    }
}
void Manager::computerSortYear(QSqlDatabase db) {
    bool db_ok = db.open();

    if(db_ok)
    {
      QSqlQuery query1("SELECT * FROM computers ORDER BY year ASC");
      while (query1.next())
      {
          //int id = query1.value(0).toInt();
          string name = query1.value(1).toString().toStdString();
          string type = query1.value(2).toString().toStdString();
          int year = query1.value(3).toInt();
          string built = query1.value(4).toString().toStdString();

          cout << name << ", " << type << ", " << year << ", " << built << endl;
      }
    }
}
