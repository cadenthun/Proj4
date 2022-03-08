#ifndef RADIXTREE
#define RADIXTREE

#include <iostream>
#include <string>
#include <map>

template <typename ValueType>
class RadixTree {
    
public:
 RadixTree();
 ~RadixTree();
void insert(std::string key, const ValueType& value);
ValueType* search(std::string key) const;
    
private:
    std::map<std::string, ValueType> dummyTree;
};

template <typename ValueType>
RadixTree<ValueType>::RadixTree()
{
    
}

template <typename ValueType>
RadixTree<ValueType>::~RadixTree()
{
    
}


template <typename ValueType>
void RadixTree<ValueType>::insert(std::string key, const ValueType &value)
{
    if (dummyTree.find(key) != dummyTree.end())
        dummyTree.erase(key);
    dummyTree.insert({key, value});
}

template <typename ValueType> 
ValueType* RadixTree<ValueType>::search(std::string key) const
{
    typename std::map<std::string, ValueType>::const_iterator it;
   // auto it = dummyTree.begin();

    it = dummyTree.find(key);
    if (it != dummyTree.end())
    {
        return const_cast<ValueType*>(&(it->second)); //Hoping this works?
      //  return &(it->second);
    }
    
    return nullptr; //couldn't find key in map
}

#endif /* RADIXTREE */
