#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "AttributeTranslator.h"
#include "RadixTree.h"

using namespace std;


AttributeTranslator::AttributeTranslator()
{}

AttributeTranslator::~AttributeTranslator(){}

bool AttributeTranslator::Load(std::string filename)
{
    ifstream infile(filename);
    if (!infile)
        return false; //couldn't open file
    
    string line;
    while (getline(infile, line))
    {
        istringstream iss(line);
        string sourceAtt;
        string sourceVal;
        string compatAtt;
        string compatVal; //remember to check for duplicates when adding compatibles to values vector
        if(!getline(iss, sourceAtt, ','))
            return false;
        if(!getline(iss, sourceVal, ','))
            return false;
        if(!getline(iss, compatAtt, ','))
            return false;
        if(!getline(iss, compatVal, ','))
            return false;
        string keyString = sourceAtt + sourceVal;
        AttValPair compatiblePair(compatAtt, compatVal);
        vector<AttValPair> tempVec;
        tempVec.push_back(compatiblePair);
        //search tree for vector currently at key, combine two vectors if possible
        vector<AttValPair>* valueAtKey = m_sourceToCompatibleMap.search(keyString);
        if (valueAtKey == nullptr)
            m_sourceToCompatibleMap.insert(keyString, tempVec);
        else
        {
            valueAtKey->insert(valueAtKey->end(), tempVec.begin(), tempVec.end());

        }
    }
    
    
    return true;
        
    
}

std::vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const
{
    vector<AttValPair> emptyVec = {};
    string sourcePair = source.attribute + source.value;
    vector<AttValPair>* returnVal = m_sourceToCompatibleMap.search(sourcePair);
    if (returnVal == nullptr)
        return emptyVec;
    return *returnVal;
}
