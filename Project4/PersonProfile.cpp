#include "PersonProfile.h"
#include "provided.h"


PersonProfile::PersonProfile(std::string name, std::string email)
{
    m_name = name;
    m_email = email;
}

PersonProfile::~PersonProfile() //get rid of this if I don't end up defining it
{
    
}

std::string PersonProfile::GetName() const
{
    return m_name;
}

std::string PersonProfile::GetEmail() const
{
    return m_email;
}

void PersonProfile::AddAttValPair(const AttValPair& attval)
{
    if (pairNotPresent(attval))
    {
        m_pairs.insert(attval.attribute, attval.value);
        m_numPairs ++;
    }
}


int PersonProfile::GetNumAttValPairs() const
{
    return m_numPairs;
}

bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const
{
    return 8908098; //temp val so program will build
}


bool PersonProfile::pairNotPresent(const AttValPair& pair)
{
    if (m_pairs.search(pair.attribute) == nullptr)
        return true;
    return false;
}
