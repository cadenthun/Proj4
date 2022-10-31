#ifndef ATTRIBUTETRANSLATOR
#define ATTRIBUTETRANSLATOR

#include <iostream>
#include "provided.h"
#include "RadixTree.h"

class AttributeTranslator
{
public:
    AttributeTranslator();
    ~AttributeTranslator();
    bool Load(std::string filename);
    std::vector<AttValPair> FindCompatibleAttValPairs(const AttValPair& source) const;
    
private:
    RadixTree<std::vector<AttValPair>> m_sourceToCompatibleMap;
};




#endif /* ATTRIBUTETRANSLATOR */
