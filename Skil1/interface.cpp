#include "interface.h"

// Starts the program, displays menu and loops while input != 5
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
        cout << setw(54) << "2.  Input new omputer" << endl;
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
    manager.addPerson();
}
void Interface::addComputer() {
    manager.addComputer();
}
// Displayes the sorting menu and loops while input != 3
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
    databaseHeader();
    manager.alphabeticSortAsc(manager.readFromFile());
}

// Calls the descending sorting function in Manager class
void Interface::sortDes() {
    databaseHeader();
    manager.alphabeticSortDes(manager.readFromFile());
}

void Interface::sortBirthYearAsc() {
    databaseHeader();
    manager.birthYearSort(manager.readFromFile());
}

void Interface::asInserted() {
    databaseHeader();
    manager.asInserted(manager.readFromFile());
}
void Interface::computerSortAsc() {
    manager.computerSortAsc(manager.readFromFile());
}
void Interface::computerSortDesc() {
    manager.computerSortDesc(manager.readFromFile());
}
void Interface::computerSortYear() {
    manager.computerSortYear(manager.readFromFile());
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
    searchWord = manager.readSearchWord();
    searchHeader();
    manager.search(manager.readFromFile(),searchWord);
}

// Calls the deletePerson function in Manager class
void Interface::deletePerson() {
    manager.deleteName(manager.readFromFile());
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
