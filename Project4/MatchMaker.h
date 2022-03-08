#ifndef MATCHMAKER
#define MATCHMAKER

#include <iostream>
#include "PersonProfile.h"
#include "MemberDatabase.h"
#include "AttributeTranslator.h"

class MatchMaker
{
public:
    MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at);
    ~MatchMaker();
    std::vector<EmailCount> IdentifyRankedMatches(std::string email, int threshold) const;
private:
    
    
};


#endif /* MATCHMAKER */
