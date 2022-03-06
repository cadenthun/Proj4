#ifndef MEMBERDATABASE
#define MEMBERDATABASE

#include <iostream>
#include "provided.h"
#include "RadixTree.h"
#include "PersonProfile.h"

class MemberDatabase
{
    MemberDatabase();
    ~MemberDatabase(); //only if necessary
    bool LoadDatabase(std::string filename);
    std::vector<std::string> FindMatchingMembers(const AttValPair& input) const;
    const PersonProfile* GetMemberByEmail(std::string email) const;
};


#endif /* MEMBERDATABASE */
