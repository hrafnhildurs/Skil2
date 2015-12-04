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

// Reads from database file (out.txt) into a vector
/*void Manager::DocString (const char doc[], vector<string> stringVec)
{
    ifstream document;
    document.open(doc);
    string temp;

    while(getline(document, temp, ';'))
    {
        stringVec.push_back(temp);
    }

    document.close();
}*/

// Helper function that returns a vector from database file
QSqlDatabase Manager::readFromFile() {
    string word;
    prog ramers;
    vector<prog> cnames;

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

    db.close();

    return db;
}

// Prints the list ordered by time inserted
void Manager::asInserted(QSqlDatabase db) {
    bool db_ok = db.open();

    if(db_ok)
    {
      QSqlQuery query1("SELECT * FROM programers");
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
      QSqlQuery query1("SELECT * FROM programers ORDER BY name ASC");
      while (query1.next())
      {
          //int id = query1.value(0).toInt();
          string name = query1.value(1).toString().toStdString();
          string sex = query1.value(2).toString().toStdString();
          int birthYear = query1.value(3).toInt();
          int deathYear = query1.value(4).toInt();

          //cout << name << ", " << sex << ", " << birthYear << ", " << deathYear << endl;
      }
    }
}

// Descending sorting function
void Manager::alphabeticSortDes(QSqlDatabase db) {
    bool db_ok = db.open();

    if(db_ok)
    {
      QSqlQuery query1("SELECT * FROM programers ORDER BY name DESC");
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
      QSqlQuery query1("SELECT * FROM programers ORDER BY birthYear ASC ");
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
void Manager::search(const char doc[], string letters) {
    ifstream in(doc);
    string line;

    if(in.is_open())
    {
        int found = 0;
        cout << "\n";
        while (getline(in, line)) {
        if (line.find(letters) != string::npos) {
            cout << "   " << line << endl;
            found++;
            }
        }
        if (found == 0)
           cout << "   " << letters << " not found" << endl;
    }
}

// Delete name from database
/*void Manager::deleteName(const char doc[], vector<string> tempVec){
    string name;
    bool found = false;

    cout << "\n";
    cout << setw(68) << "Enter the name you want to delete: ";
    cin >> name;

    for(unsigned int i = 0; i < tempVec.size(); ++i)
    {
        if(tempVec[i].substr(0, name.length()) == name)  //searching for the name in the vector
        {
            found = true;
            tempVec.erase(tempVec.begin() + i);           //deleting the name from the vector
            cout << setw(54) << "Name has been erased!"<< endl;
            i = 0;                                  //reseting the search
        }
    }

    if(!found)
        cout << setw(60) << "Name not found in database." << endl;
*/

   // ofstream outs(doc/*, ios::out | ios::trunc*/);             //printing a new list from the vec to the file
                                                            //were the name has benn deleted
/*    for(vector<string>::const_iterator newlist = tempVec.begin(); newlist != tempVec.end(); newlist++)
    {
        outs << *newlist << endl;
    }
    outs.close();
}*/
