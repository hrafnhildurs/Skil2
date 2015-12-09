#ifndef RELATIONS_H
#define RELATIONS_H
#include <string>
using namespace std;

/* Class that handles relations between a computer scientist
 * and a computer in a seperate table in the database, containing
 * the IDs of each computer scientist and computer that are joined
 * together.
*/
class relations
{
public:
    relations();
    relations(int &cid, int &pid);
    string returnPname();
    string returnCname();
    int returnCid();
    int returnPid();
    int returnRid();

    void addToRelations(int cid, int pid);
    void addNamesToRelations(int id, string c, string p);
private:
    string rcname;
    string rpname;
    int rcid;
    int rpid;
    int rid;
};

#endif // RELATIONS_H
