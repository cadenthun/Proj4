
#include "MemberDatabase.h"


MemberDatabase::MemberDatabase()
{
    
}

MemberDatabase::~MemberDatabase() {} //only if necessary


bool MemberDatabase::LoadDatabase(std::string filename)
{
    return false; //dummy
}

std::vector<std::string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const
{
    std::vector<std::string> dummyVec;
    return dummyVec; //dummy
}

const PersonProfile* MemberDatabase::GetMemberByEmail(std::string email) const
{
    return nullptr; //dummy
}
