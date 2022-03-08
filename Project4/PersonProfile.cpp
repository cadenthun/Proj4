#include <iostream>
#include <string>

#include "PersonProfile.h"
#include "provided.h"
#include "RadixTree.h"


PersonProfile::PersonProfile(std::string name, std::string email)
{
    m_name = name;
    m_email = email;
    m_numPairs = 0;
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
        m_keyContainer.push_back(attval.attribute);
    }
    return;
}


int PersonProfile::GetNumAttValPairs() const
{
    return m_numPairs;
}

bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const
{
    if (m_keyContainer.size() < 1)
        return false;
   
    std::string* valuePtr = m_pairs.search(m_keyContainer[attribute_num]);
    if (valuePtr == nullptr)
        return false;
    attval.attribute = m_keyContainer[attribute_num];
    attval.value = *valuePtr;
    
    return true;
}


bool PersonProfile::pairNotPresent(const AttValPair& pair)
{
    std::string* returnVal = m_pairs.search(pair.attribute);
    if (returnVal == nullptr)
        return true;
    if (*returnVal == pair.attribute)
        return false;
    return true;
    
}
