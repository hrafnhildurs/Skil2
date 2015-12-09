#ifndef COMPUTER
#define COMPUTER
#include <string>
using namespace std;

/* Class that handles everything that has to do with each computers
 * inserted into the databse.
*/

class computer
{
public:
    // Constructors
    computer();
    computer(string& cn, int& cy, string& ct, string& cb);

    // Helper functions to return private variable values
    int returnId();
    string returnComName();
    int returnComYear();
    string returnComType();
    string returnComBuilt();

    // Helper function for relations
    void addToComputer(int id, string cn, int cy, string ct, string cb);
private:
    int id;
    string cname;
    int cyear;
    string ctype;
    string cbuilt;
};

#endif // COMPUTER

