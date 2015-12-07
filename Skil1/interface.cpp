#include "interface.h"

// Starts the program, displays menu and loops while input != 7
void Interface::start() {
    char number = 0;
    do
    {
        cout << "\n";
        cout << setw(58) << "-------------------------" << endl;
        cout << setw(59) <<" |    Famous programmers   |" << endl;
        cout << setw(58) << "-------------------------" << endl;
        cout << "\n\n";
        cout << setw(48) << "Menu" << endl;
        cout << "   ======================================================================================" << endl;
        cout << setw(53) << "1.  Input new person" << endl;
        cout << setw(55) << "2.  Input new computer" << endl;
        cout << setw(57) << "3.  View list of persons" << endl;
        cout << setw(59) << "4.  View list of computers" << endl;
        cout << setw(64) << "5.  Delete person from database" << endl;
        cout << setw(43) << "6.  Search" << endl;
        cout << setw(42) << "7.  Exit " << endl;
        cout << "   ======================================================================================" << endl;
        cout << "\n";
        cout << setw(55) << "Enter your selection: ";
        number = indexSwitch();
    }while(number != '7');
}

// Takes input from user and calls appropriate functions in Manager class
char Interface::indexSwitch() {
    char number;
    cin >> number;
    switch(number)
    {
        case '1':
            addPerson();
            return '1';
            break;
        case '2':
            addComputer();
            return '2';
            break;
        case '3':
            sortMenu();
            return '3';
            break;
        case '4':
            computerSortMenu();
            return '4';
            break;
        case '5':
            deletePerson();
            return '5';
            break;
        case '6':
            search();
            return '6';
            break;
        case '7':
            return '7';
            break;
    default:
            cout << "   Invalid input." << endl;
            return '0';
            break;
    }
}

// Helper function that calls addPerson()function from Manager class
void Interface::addPerson() {
    char ans;
    cout << "Is the person alive? (y/n) ";
    cin >> ans;

    string name;
    string sex;
    int born;
    int died;

    if(ans == 'y' || ans == 'Y') {
        cout << "Name: ";
        cin >> ws;
        getline(cin, name);
        cout << "Sex: ";
        getline(cin, sex);
        cout << "Birth year: ";
        cin >> born;

        manager.addPersonAlive(name, sex, born);
    }
    else {
        cout << "Name: ";
        cin >> ws;
        getline(cin, name);
        cout << "Sex: ";
        getline(cin, sex);
        cout << "Birth year: ";
        cin >> born;
        cout << "Death year: ";
        cin >> died;

        manager.addPersonDead(name, sex, born, died);
    }
    cout << "   Person added to database." << endl;
}


void Interface::addComputer() {
    string cname;
    int cyear;
    string ctype;
    string cbuilt;

    cout << "Name: ";
    cin >> ws;
    getline(cin, cname);
    cout << "Year built: ";
    cin >> cyear;
    cout << "Type: ";
    cin >> ctype;
    char ans;
    cout << "was it made ?(y/n): ";
    cin >> ans;
    if(ans == 'y')
        cbuilt = "yes";
    else
        cbuilt = "no";
    manager.addComputer(cname, cyear, ctype, cbuilt);
}

// Displayes the sorting menu and loops while input != 5
void Interface::sortMenu() {
    char number = 0;
    do
    {
        cout << "\n\n";
        cout << setw(52) << "Sorting menu" << endl;
        cout << "   ======================================================================================" << endl;
        cout << setw(59) << "1.  Ascending alphabetic sort" << endl;
        cout << setw(60) << "2.  Descending alphabetic sort" << endl;
        cout << setw(52) << "3.  Sort by date added" << endl;
        cout << setw(57) << "4.  Sort by birth year ACS " << endl;
        cout << setw(49) << "5.  Exit sort menu " << endl;
        cout << "   ======================================================================================" << endl;
        cout << "\n";
        cout << setw(55) << "Enter your selection: ";
        number = sortSwitch();
    }while(number != '5');
    cout << "\n\n";
}

// Handles input from user and calls appropriate sorting functions in Manager class
char Interface::sortSwitch() {
    char number;


    cin >> number;
    switch(number)
    {
        case '1':
            sortAsc();
            return '1';
            break;
        case '2':
            sortDes();
            return '2';
            break;
        case '3':
            asInserted();
            return '3';
            break;
        case '4':
            sortBirthYearAsc();
            return '4';
            break;
        case '5':
            return '5';
            break;
        default:
            cout << "   Invalid input.";
            return '0';
            break;
        }
}

// Calls the ascending sorting function in Manager class
void Interface::sortAsc() {
    vector<person> tmp = manager.alphabeticSortAsc();
    databaseHeader();
    writeOutPersonVector(tmp);
}

// Calls the descending sorting function in Manager class
void Interface::sortDes() {
    vector<person> tmp = manager.alphabeticSortDes();
    databaseHeader();
    writeOutPersonVector(tmp);
}

void Interface::sortBirthYearAsc() {
    vector<person> tmp = manager.birthYearSort();
    databaseHeader();
    writeOutPersonVector(tmp);
}

void Interface::asInserted() {
    vector<person> tmp = manager.asInserted();
    databaseHeader();
    writeOutPersonVector(tmp);
}
void Interface::computerSortAsc() {
    vector<computer> tmp = manager.computerSortAsc();
    //cDatabaseHeader();
    writeOutComVector(tmp);
}
void Interface::computerSortDesc() {
    vector<computer> tmp = manager.computerSortDesc();
    //cDatabaseHeader();
    writeOutComVector(tmp);
}
void Interface::computerSortYear() {
    vector<computer> tmp = manager.computerSortYear();
    //cDatabaseHeader();
    writeOutComVector(tmp);
}

void Interface::computerSortMenu() {
    char number = 0;
    do
    {
        cout << "\n\n";
        cout << setw(52) << "Sorting menu" << endl;
        cout << "   ======================================================================================" << endl;
        cout << setw(59) << "1.  Ascending alphabetic sort" << endl;
        cout << setw(60) << "2.  Descending alphabetic sort" << endl;
        cout << setw(52) << "3.  Sort by year built" << endl;
        cout << setw(49) << "4.  Exit sort menu " << endl;
        cout << "   ======================================================================================" << endl;
        cout << "\n";
        cout << setw(55) << "Enter your selection: ";
        number = computerSortSwitch();
    }while(number != '4');
    cout << "\n\n";
}
char Interface::computerSortSwitch() {
    char number;
    cin >> number;

    switch(number)
    {
        case '1':
            computerSortAsc();
            return '1';
            break;
        case '2':
            computerSortDesc();
            return '2';
            break;
        case '3':
            computerSortYear();
            return '3';
            break;
        case '4':
            return '4';
            break;
        default:
            cout << "   Invalid input.";
            return '0';
            break;
        }
}

// Calls the search function in Manager class
void Interface::search() {
    string searchWord;
    cout << setw(52) << "Enter search word: ";
    cin >> searchWord;
    searchHeader();
    vector<person> search = manager.search(searchWord);
    writeOutPersonVector(search);
}

// Calls the deletePerson function in Manager class
void Interface::deletePerson() {
    string del;
    cout << "Enter a full name of the person you want to delete: ";
    cin >> ws;
    getline(cin, del);
    manager.deleteName(del);
}

// Prints out the database header when list is displayed
void Interface::databaseHeader()
{
    cout << "\n";
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << setw(40) << "Database" << endl;
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << "\n";
    cout << setw(10) << "Name" << setw(31) << "Sex" << setw(12) << "Birth year" << setw(13) << "Death year" << setw(16) << "Date/Time" <<endl;
    cout << "   ======================================================================================" << endl;
}

// Prints out the search header when search results are displayed
void Interface::searchHeader()
{
    cout << "\n";
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << setw(40) << "Search results" << endl;
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << "\n";
    cout << setw(10) << "Name" << setw(31) << "Sex" << setw(12) << "Birth year" << setw(13) << "Death year" << setw(16) << "Date/time" << endl;
    cout << "   ======================================================================================" << endl;
}

void Interface::writeOutPersonVector(vector<person> pers) {
    for (size_t i = 0 ; i < pers.size() ; i++) {
        cout << pers[i].returnName() << ", " <<
                pers[i].returnSex() << ", " <<
                pers[i].returnBirthYear() << ", " <<
                pers[i].returnDeathYear() << endl;
    }
}

void Interface::writeOutComVector(vector<computer> computer) {
    for (size_t i = 0 ; i < computer.size() ; i++) {
        cout << computer[i].returnComName() << ", " <<
                computer[i].returnComYear() << ", " <<
                computer[i].returnComType() << ", " <<
                computer[i].returnComBuilt() << endl;
    }
}
