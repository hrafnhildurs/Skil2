#include "interface.h"

// Starts the program, displays menu and loops while input != 7
void Interface::start() {
    char number = 0;
    do {
        cout << "\n";
        cout << setw(60) << "----------------------------" << endl;
        cout << setw(60) <<"|  Famous programmers 2.0  |" << endl;
        cout << setw(60) << "----------------------------" << endl;
        cout << "\n\n";
        cout << setw(48) << "Menu" << endl;
        cout << "   ======================================================================================" << endl;
        cout << setw(56) << "1.  Input into database" << endl;
        cout << setw(58) << "2.  View list in database" << endl;
        cout << setw(57) << "3.  Delete from database" << endl;
        cout << setw(43) << "4.  Search" << endl;
        cout << setw(42) << "5.  Exit " << endl;
        cout << "   ======================================================================================" << endl;
        cout << "\n";
        cout << setw(55) << "Enter your selection: ";
        number = indexSwitch();
    }while(number != '5');
}

// Takes input from user and calls appropriate functions in Manager class
char Interface::indexSwitch() {
    char number;
    cin >> number;
    switch(number) {
        case '1':
            system("CLS");
            inputMenu();
            return '1';
            break;
        case '2':
            system("CLS");
            viewMenu();
            return '2';
            break;
        case '3':
            system("CLS");
            deleteMenu();
            return '3';
            break;
        case '4':
            system("CLS");
            searchMenu();
            return '4';
            break;
        case '5':
            return '5';
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
    cout << endl;
    cout << setw(60) << "Is the person alive? (y/n) ";
    cin >> ans;
    cout << endl;

    string name;
    string sex;
    int born;
    int died;

    if(ans == 'y' || ans == 'Y') {
        cout << setw(39) << "Name: ";
        cin >> ws;
        getline(cin, name);
        cout << setw(38) << "Sex: ";
        getline(cin, sex);
        cout << setw(45) << "Birth year: ";
        cin >> born;

        manager.addPersonAlive(name, sex, born);
    }
    else {
        cout << setw(39) << "Name: ";
        cin >> ws;
        getline(cin, name);
        cout << setw(38) << "Sex: ";
        getline(cin, sex);
        cout << setw(45) << "Birth year: ";
        cin >> born;
        cout << setw(45) << "Death year: ";
        cin >> died;

        manager.addPersonDead(name, sex, born, died);
    }
    cout << endl;
    cout << setw(58) << "Person added to database." << endl;
}


void Interface::addComputer() {
    string cname;
    int cyear;
    string ctype;
    string cbuilt;

    cout << endl;
    cout << setw(39) << "Name: ";
    cin >> ws;
    getline(cin, cname);
    cout << setw(45) << "Year built: ";
    cin >> cyear;
    cout << setw(39) << "Type: ";
    cin >> ctype;
    char ans;
    cout << setw(53) << "was it made ?(y/n): ";
    cin >> ans;
    if(ans == 'y')
        cbuilt = "yes";
    else
        cbuilt = "no";
    manager.addComputer(cname, cyear, ctype, cbuilt);
    cout << endl;
    cout << setw(60) << "computer added to database." << endl;
}

// Displays the sorting menu and loops while input != 5
void Interface::sortMenu() {
    char number = 0;
    do {
        cout << "\n\n";
        cout << setw(52) << "Sorting menu" << endl;
        cout << "   ======================================================================================" << endl;
        cout << setw(59) << "1.  Ascending alphabetic sort" << endl;
        cout << setw(60) << "2.  Descending alphabetic sort" << endl;
        cout << setw(52) << "3.  Sort by date added" << endl;
        cout << setw(57) << "4.  Sort by birth year ASC " << endl;
        cout << setw(51) << "5.  Exit to view menu" << endl;
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
    switch(number) {
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

void Interface::computerAsInserted() {
    vector<computer> tmp = manager.computerAsInserted();
    cDatabaseHeader();
    writeOutComVector(tmp);
}

void Interface::computerSortAsc() {
    vector<computer> tmp = manager.computerSortAsc();
    cDatabaseHeader();
    writeOutComVector(tmp);
}

void Interface::computerSortDesc() {
    vector<computer> tmp = manager.computerSortDesc();
    cDatabaseHeader();
    writeOutComVector(tmp);
}

void Interface::computerSortYear() {
    vector<computer> tmp = manager.computerSortYear();
    cDatabaseHeader();
    writeOutComVector(tmp);
}

void Interface::computerSortMenu() {
    char number = 0;
    do {
        cout << "\n\n";
        cout << setw(52) << "Sorting menu" << endl;
        cout << "   ======================================================================================" << endl;
        cout << setw(59) << "1.  Ascending alphabetic sort" << endl;
        cout << setw(60) << "2.  Descending alphabetic sort" << endl;
        cout << setw(52) << "3.  Sort by year built" << endl;
        cout << setw(51) << "4.  Exit to view menu" << endl;
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

    switch(number) {
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
    cout << endl;
    cout << setw(52) << "Enter search word: ";
    cin >> searchWord;
    searchHeader();
    vector<person> search = manager.search(searchWord);
    writeOutPersonVector(search);
}

void Interface::searchComp() {
    string searchWord;
    cout << endl;
    cout << setw(52) << "Enter search word: ";
    cin >> searchWord;
    cSearchHeader();
    vector<computer> search = manager.searchComp(searchWord);
    writeOutComVector(search);
}

// Calls the deletePerson function in Manager class
void Interface::deletePerson() {
    string del;
    cout << endl;
    cout << setw(55) << "Enter a full name of the person you want to delete: ";
    cin >> ws;
    getline(cin, del);
    manager.deleteName(del);
}

// Calls the deleteComputer function in Manager class
void Interface::deleteComputer() {
    string del;
    cout << endl;
    cout << setw(57) << "Enter a full name of the computer you want to delete: ";
    cin >> ws;
    getline(cin, del);
    manager.deleteComputer(del);
}

void Interface::deleteRelation() {
    int del;
    cout << endl;
    cout << setw(52) << "Enter the ID of a relation you want yo remove: ";
    cin >> del;
    manager.deleteRelation(del);
}

void Interface::relation() {
    vector<relations> tmp = manager.relation();
    relationsHeader();
    writeOutRelations(tmp);
}

// Prints out the database header when list is displayed
void Interface::databaseHeader() {
    cout << "\n";
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << setw(58) << "Computer Scientist Database" << endl;
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << "\n";
    cout << setw(7) << "Name" << setw(42) << "Sex" << setw(19) << "Birth year" << setw(19) << "Death year" <<endl;
    cout << "   ======================================================================================" << endl;
}

// Prints out the database header when list is displayed
void Interface::cDatabaseHeader() {
    cout << "\n";
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << setw(55) << "Computer Database" << endl;
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << "\n";
    cout << setw(7) << "Name" << setw(43) << "Type" << setw(19) << "Year built" << setw(19) << "Built"<<endl;
    cout << "   ======================================================================================" << endl;
}

void Interface::idDatabaseHeader() {
    cout << "\n";
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << setw(58) << "Computer Scientist Database" << endl;
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << "\n";
    cout << setw(7) << "ID" << setw(8) << "Name" << setw(36) << "Sex" << setw(19) << "Birth year" << setw(19) << "Death year" <<endl;
    cout << "   ======================================================================================" << endl;
}

// Prints out the database header when list is displayed
void Interface::idcDatabaseHeader() {
    cout << "\n";
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << setw(55) << "Computer Database" << endl;
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << "\n";
    cout << setw(7) << "ID" << setw(8) << "Name" << setw(36) << "Type" << setw(20) << "Year built" << setw(17) << "Built"<<endl;
    cout << "   ======================================================================================" << endl;
}

// Prints out the search header when search results are displayed
void Interface::searchHeader() {
    cout << "\n";
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << setw(55) << "Search results" << endl;
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << "\n";
    cout << setw(10) << "Name" << setw(38) << "Sex" << setw(20) << "Birth year" << setw(19) << "Death year" << endl;
    cout << "   ======================================================================================" << endl;
}

void Interface::cSearchHeader() {
    cout << "\n";
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << setw(55) << "Search results" << endl;
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << "\n";
    cout << setw(10) << "Name" << setw(38) << "Type" << setw(22) << "Year built" << setw(18) << "Built" << endl;
    cout << "   ======================================================================================" << endl;
}

void Interface::relationsHeader() {
    cout << "\n";
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << setw(51) << "Relations" << endl;
    cout << "   --------------------------------------------------------------------------------------" << endl;
    cout << "\n";
    cout << setw(7) << "ID" << setw(15) << "Programmer" << setw(48) << "Computer" <<endl;
    cout << "   ======================================================================================" << endl;
}

void Interface::writeOutPersonVector(vector<person> pers) {
    for (size_t i = 0 ; i < pers.size() ; i++) {
        cout << "   " << setw(pers[i].returnName().length()) << pers[i].returnName() <<
                setw(21 + (25 - pers[i].returnName().length())) << pers[i].returnSex() <<
                setw(16) << pers[i].returnBirthYear();
                if(pers[i].returnDeathYear() != 0)
                    cout << setw(20) << pers[i].returnDeathYear() << endl;
                else
                    cout << endl;
    }
}

void Interface::writeOutPersonVectorId(vector<person> pers) {
    for (size_t i = 0 ; i < pers.size() ; i++) {
        cout << setw(7) << pers[i].returnId() << "    " <<
                setw(pers[i].returnName().length()) << pers[i].returnName() <<
                setw(15 + (25 - pers[i].returnName().length())) << pers[i].returnSex() <<
                setw(16) << pers[i].returnBirthYear();
                if(pers[i].returnDeathYear() != 0)
                    cout << setw(20) << pers[i].returnDeathYear() << endl;
                else
                    cout << endl;
    }
}

void Interface::writeOutComVector(vector<computer> computer) {
    for (size_t i = 0 ; i < computer.size() ; i++) {
        cout << "   " << setw(computer[i].returnComName().length())
             << computer[i].returnComName()
             << setw(24 +(25 - computer[i].returnComName().length()))
             << computer[i].returnComType() << setw(15)
             << computer[i].returnComYear() << setw(20)
             << computer[i].returnComBuilt() << endl;
    }
}

void Interface::writeOutComVectorId(vector<computer> computer) {
    for (size_t i = 0 ; i < computer.size() ; i++) {
        cout << setw(7) << computer[i].returnId() << "    "
             << setw(computer[i].returnComName().length())
             << computer[i].returnComName()
             << setw(17 +(25 - computer[i].returnComName().length()))
             << computer[i].returnComType() << setw(16)
             << computer[i].returnComYear() << setw(18)
             << computer[i].returnComBuilt() << endl;
    }
}

void Interface::writeOutRelations(vector<relations> relation) {
    for (size_t i = 0 ; i < relation.size() ; i++) {
        cout << setw(7) << relation[i].returnRid()
             << setw(5 + relation[i].returnCname().length())
             << relation[i].returnCname()
             << setw(25 +(25 - relation[i].returnCname().length()) + (relation[i].returnPname().length()))
             << relation[i].returnPname()
             << endl;
    }
}

void Interface::inputMenu() {
    char number = 0;
    do {
        cout << "\n\n";
        cout << setw(52) << "Input menu" << endl;
        cout << "   ======================================================================================" << endl;
        cout << setw(53) << "1.  Input new person" << endl;
        cout << setw(55) << "2.  Input new computer" << endl;
        cout << setw(55) << "3.  Input new relation" << endl;
        cout << setw(53) << "4.  Exit input menu " << endl;
        cout << "   ======================================================================================" << endl;
        cout << "\n";
        cout << setw(55) << "Enter your selection: ";
        number = inputSwitch();
    }while(number != '4');
    cout << "\n\n";
}

char Interface::inputSwitch() {
    char number;
    cin >> number;

    switch(number) {
        case '1':
            addPerson();
            return '1';
            break;
        case '2':
            addComputer();
            return '2';
            break;
        case '3':
            addRelations();
            break;
        case '4':
            system("CLS");
            return '4';
            break;
        default:
            cout << "   Invalid input.";
            return '0';
            break;
        }
    return '0';
}

void Interface::viewMenu() {
    char number = 0;
    do{
        cout << "\n\n";
        cout << setw(52) << "View menu" << endl;
        cout << "   ======================================================================================" << endl;
        cout << setw(57) << "1.  View list of persons" << endl;
        cout << setw(59) << "2.  View list of computers" << endl;
        cout << setw(51) << "3.  View relations" << endl;
        cout << setw(51) << "4.  Exit view menu" << endl;
        cout << "   ======================================================================================" << endl;
        cout << "\n";
        cout << setw(55) << "Enter your selection: ";
        number = viewSwitch();
    cout << "\n\n";
    }while(number != '4');
}

char Interface::viewSwitch() {
    char number;
    cin >> number;

    switch(number) {
        case '1':
            sortMenu();
            return '1';
            break;
        case '2':
            computerSortMenu();
            return '2';
            break;
        case '3':
            relation();
            return '3';
            break;
        case '4':
            system("CLS");
            return '4';
            break;
        default:
            cout << "   Invalid input.";
            return '0';
            break;
        }
}

void Interface::deleteMenu() {
    char number = 0;
    do {
        cout << "\n\n";
        cout << setw(55) << "Delete menu" << endl;
        cout << "   ======================================================================================" << endl;
        cout << setw(64) << "1.  Delete person from database" << endl;
        cout << setw(66) << "2.  Delete computer from database" << endl;
        cout << setw(66) << "3.  Delete relation from database" << endl;
        cout << setw(54) << "4.  Exit delete menu " << endl;
        cout << "   ======================================================================================" << endl;
        cout << "\n";
        cout << setw(55) << "Enter your selection: ";
        number = deleteSwitch();
    }while(number != '4');
    cout << "\n\n";
}

char Interface::deleteSwitch() {
    char number;
    cin >> number;

    switch(number) {
        case '1':
            sortAsc();
            deletePerson();
            return '1';
            break;
        case '2':
            computerSortAsc();
            deleteComputer();
            return '2';
            break;
        case '3':
            relation();
            deleteRelation();
            return '3';
            break;
        case '4':
            system("CLS");
            return '4';
            break;
            default:
            cout << "   Invalid input.";
            return '0';
            break;
        }
}

void Interface::searchMenu() {
    char number = 0;
    do {
        cout << "\n\n";
        cout << setw(55) << "Search menu" << endl;
        cout << "   ======================================================================================" << endl;
        cout << setw(50) << "1.  Person search" << endl;
        cout << setw(52) << "2.  Computer search" << endl;
        cout << setw(54) << "3.  Exit search menu " << endl;
        cout << "   ======================================================================================" << endl;
        cout << "\n";
        cout << setw(55) << "Enter your selection: ";
        number = searchSwitch();
    }while(number != '3');
    cout << "\n\n";
}

char Interface::searchSwitch() {
    char number;
    cin >> number;

    switch(number) {
        case '1':
            search();
            return '1';
            break;
        case '2':
            searchComp();
            return '2';
            break;
        case '3':
            system("CLS");
            return '3';
            break;
        default:
            cout << "   Invalid input.";
            return '0';
            break;
        }
}

// Joins ID's of person and computer in a relations table in the database
void Interface::addRelations() {
    vector<person> per = manager.asInserted();
    vector<computer> com = manager.computerAsInserted();

    idDatabaseHeader();
    writeOutPersonVectorId(per);
    int pid = choosePerson();
    idcDatabaseHeader();
    writeOutComVectorId(com);
    int cid = chooseComputer();

    manager.addRelations(pid, cid);
}

int Interface::choosePerson() {
    int pid;
    cout << endl;
    cout << setw(50) << "Enter the ID of a Computer Scientist to add: ";
    cin >> pid;
    return pid;
}

int Interface::chooseComputer() {
    int cid;
    cout << endl;
    cout << setw(40) << "Enter the ID of a computer to add: ";
    cin >> cid;
    return cid;
}
