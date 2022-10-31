#include <iostream>
#include <fstream>
#include <sstream>
#include "MemberDatabase.h"
using namespace std;


MemberDatabase::MemberDatabase()
{
    
}

MemberDatabase::~MemberDatabase() {} //only if necessary


bool MemberDatabase::LoadDatabase(std::string filename)
{
    //if two members have the same email address, return false
    
    ifstream infile(filename);
    if (!infile)
        return false; //couldn't open file
    
    // chunk of code below is what needs to happen for each person in the members.txt file
    for (;;)
    {
        string name = "";
        string email = "";
        string numberOfPairs;
        string pair = "";
        string line = "";
        int numPairs; 
        
        if (!getline(infile, name))
            return false;
        if (!getline(infile, email))
            return false;
        if (!getline(infile, numberOfPairs))
            return false;
        istringstream iss(numberOfPairs);
        iss >> numPairs;
        
        PersonProfile pp(name, email);
        //code to process attval pairs below
        //while (getline(infile, pair) && !pair.empty())
        for (int i = 0; i < numPairs; i++)
        {
            vector<string> tempVec;
            pair = "";
            if (!getline(infile, pair))
                return false;
            tempVec.push_back(email);
            vector<string>* valueAtKey = m_attValToEmailMap.search(pair);
            if (valueAtKey == nullptr)
                m_attValToEmailMap.insert(pair, tempVec);
            else
            {
                valueAtKey->insert(valueAtKey->end(), tempVec.begin(), tempVec.end());

            }
            string att;
            string val;
            istringstream iss(pair);
            if(!getline(iss, att, ','))
                return false;
            if(!getline(iss, val, ','))
                return false;
            AttValPair avPair(att, val);
            pp.AddAttValPair(avPair);
        }
        
        if (m_emailToPersonProfileMap.search(email) != nullptr)
            return false; //duplicate emails
        
        m_emailToPersonProfileMap.insert(email, pp); 
        if (!getline(infile, line)) //should read in empty line, get ready for next profile to be processed
            break;
        //code to process all attval pairs above
        
    }
    return true;
}

std::vector<std::string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const
{
    string keyString = input.attribute + "," + input.value;
    return *m_attValToEmailMap.search(keyString);
}

const PersonProfile* MemberDatabase::GetMemberByEmail(std::string email) const
{
    return m_emailToPersonProfileMap.search(email);
}

