#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "AttributeTranslator.h"
#include "RadixTree.h"

using namespace std;


AttributeTranslator::AttributeTranslator()
{
    
}

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
        //HAVE TO CONTROL FOR DUPLICATES; NOT HANDLED AT THIS POINT WHATSOEVER
    }
    
    
    return true;
    
    //can call getline, get, other functions that can be called on a cin object
    //can use substr, find
        //  find gives position in the string (as an int) of the first occurrence of the char it is passed; could be useful for identifying where commas are, as commas separate each attribute/value
        
    
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
