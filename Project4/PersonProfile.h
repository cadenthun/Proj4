#ifndef PERSON_PROFILE
#define PERSON_PROFILE

#include <iostream>
#include <vector> // get rid of this after I implement the radix tree
#include "provided.h"
#include "RadixTree.h" //will be necessary eventually

class PersonProfile
{
public:
    PersonProfile(std::string name, std::string email);
    ~PersonProfile(); //get rid of this if I don't end up defining it
    std::string GetName() const;
    std::string GetEmail() const;
    void AddAttValPair(const AttValPair& attval);
    int GetNumAttValPairs() const;
    bool GetAttVal(int attribute_num, AttValPair& attval) const;
    
    
private:
    int m_numPairs;
    std::string m_name;
    std::string m_email;
    RadixTree<std::string> m_pairs; //eventually this will have to be a radix tree
    std::vector<std::string> m_keyContainer;
    bool pairNotPresent(const AttValPair& pair);
};

#endif /* PERSON_PROFILE */
