#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "MatchMaker.h"
#include "PersonProfile.h"
#include "provided.h"
using namespace std;


MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at)
{
    m_database = mdb;
    m_translator = at;
}

MatchMaker::~MatchMaker()
{}

bool operator<(const AttValPair& a, const AttValPair& b) //comparisons of AttValPairs
{
    string aString = a.attribute + a.value;
    string bString = b.attribute + b.value;
    if (aString < bString)
        return true;
    return false;
}

bool operator<(const EmailCount& a, const EmailCount& b)
{
    if (a.count > b.count)
        return true;
    if (a.count == b.count)
    {
        if (a.email < b.email)
            return true;
    }
    return false;
}

std::vector<EmailCount> MatchMaker::IdentifyRankedMatches(std::string email, int threshold) const
{
    PersonProfile pp = *m_database.GetMemberByEmail(email);
    set<AttValPair> compatiblePairs;
    map<string, int> compatibleMembers;

    for (int i = 0; i < pp.GetNumAttValPairs(); i++) //creates a set of compatible pairs
    {
        AttValPair pair;
        pp.GetAttVal(i, pair);
        vector<AttValPair> compatibles =  m_translator.FindCompatibleAttValPairs(pair);
        for (int i = 0; i < compatibles.size(); i++)
            compatiblePairs.insert(compatibles[i]); //should take care of duplicates because is a set
    }
    
    set<AttValPair>::iterator it;
    for (it = compatiblePairs.begin(); it != compatiblePairs.end(); it++) 
    {
        vector<string> matchingMembers = m_database.FindMatchingMembers(*it);
        for (int i = 0; i < matchingMembers.size(); i++)
        {
            if (compatibleMembers.find(matchingMembers[i]) == compatibleMembers.end())
                compatibleMembers.insert(pair<string,int>(matchingMembers[i],1));
            else
            {
                map<string, int>::iterator it2 = compatibleMembers.find(matchingMembers[i]);
                (*it2).second++;
            }
        }
    }
    //above loop should create a map of every member with at least one compatible pair, and link their email to their number of compatible pairs
    
    vector<EmailCount> vectorOfEmailCounts;
    map<string, int>::iterator it3;
    for (it3 = compatibleMembers.begin(); it3 != compatibleMembers.end(); it3++) //add emailCounts to vector of emailcounts
    {
        if ((*it3).second >= threshold)
        {
            EmailCount nextEmailCount((*it3).first, (*it3).second);
            vectorOfEmailCounts.push_back(nextEmailCount);
        }
    }
    
    sort(vectorOfEmailCounts.begin(), vectorOfEmailCounts.end());

    return vectorOfEmailCounts;
}
