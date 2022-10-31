#ifndef MEMBERDATABASE
#define MEMBERDATABASE

#include <iostream>
#include "provided.h"
#include "RadixTree.h"
#include "PersonProfile.h"

class MemberDatabase
{
public:
    MemberDatabase();
    ~MemberDatabase(); //only if necessary
    bool LoadDatabase(std::string filename);
    std::vector<std::string> FindMatchingMembers(const AttValPair& input) const;
    const PersonProfile* GetMemberByEmail(std::string email) const;
private:
    RadixTree<std::vector<std::string>> m_attValToEmailMap;
    RadixTree<PersonProfile> m_emailToPersonProfileMap;
};


#endif /* MEMBERDATABASE */
