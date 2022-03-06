#ifndef RADIXTREE
#define RADIXTREE

#include <iostream>
#include <unordered_map>

template <typename ValueType>
class RadixTree {
public:
 RadixTree();
 ~RadixTree();
 void insert(std::string key, const ValueType& value);
ValueType* search(std::string key) const;
private: //get rid of this once I implement the Radix Tree
  //  std::unordered_map<std::string, ValueType> m_tempMap;
    struct Node
    {
        Node* edges[180];
        ValueType value;
        bool endOfWord;
        Node()
        {
            for (int i = 0; i < 180; i++)
                edges[i] = nullptr;
        }
    };
    Node root;
    
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
    m_tempMap.insert_or_assign(key, value);
}

template <typename ValueType> 
ValueType* RadixTree<ValueType>::search(std::string key) const
{
    typename std::unordered_map<std::string, ValueType>::const_iterator it;
    it = m_tempMap.find(key);
    if (it == m_tempMap.end())
        return nullptr;
    return &(it->second);
}

#endif /* RADIXTREE */
