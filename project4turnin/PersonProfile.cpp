#include <iostream>
#include <string>
#include <set>
#include <vector>

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
        //create temporary set containing attval.value; merge that set with the one already mapped to by attval.attribute, if present, and merge the two sets and insert the result; if not present, insert attribute w/ tempset into RadixTree; set should take care of situations where duplicates occur
        std::set<std::string> tempSet;
        tempSet.insert(attval.value);
        std::set<std::string>* valueAtKey = m_pairs.search(attval.attribute);
        if (valueAtKey != nullptr)
        {
            valueAtKey->insert(tempSet.begin(), tempSet.end());
            m_valueContainer.push_back(attval.value);
        }
        else
        {
            m_pairs.insert(attval.attribute, tempSet);
            m_valueContainer.push_back(attval.value);
        }

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
   
    std::set<std::string>* valuePtr = m_pairs.search(m_keyContainer[attribute_num]);
    if (valuePtr == nullptr)
        return false;
    attval.attribute = m_keyContainer[attribute_num];
    attval.value = m_valueContainer[attribute_num];
    
    return true;
}


bool PersonProfile::pairNotPresent(const AttValPair& pair)
{
    std::set<std::string>* returnVal = m_pairs.search(pair.attribute);
    if (returnVal == nullptr || returnVal->find(pair.value) == returnVal->end())
        return true;
    return false;
}
