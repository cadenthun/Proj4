
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


     it = dummyTree.find(key);
     if (it != dummyTree.end())
     {
         return const_cast<ValueType*>(&(it->second));
     }
     
     return nullptr; //couldn't find key in map
 }

 #endif // RADIXTREE
 



/*
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
    struct Node
    {
        std::string nString;
        Node* edges[128];
        bool endOfWord;
        ValueType nValue;
        
        Node(std::string string, ValueType value)
        : nValue(value), nString(string)
        {
            for (int i = 0; i < 128; i++)
                edges[i] = nullptr;
            endOfWord = true;
        }
        
        Node(std::string string, ValueType value, Node* oldNodeEdges[]) //used if I want to copy an old node's array over to the new one
        : nValue(value), nString(string)
        {
            if (oldNodeEdges != nullptr)
                for (int i = 0; i < 128; i++)
                    edges[i] = oldNodeEdges[i];
            else
            {
                for (int i = 0; i < 128; i++)
                    edges[i] = nullptr;
            }
            endOfWord = true;
        }
        
    };
    
    Node* m_root[128];
    Node* m_currNode;
    void insertNoMorePrefixes(Node* arr[], int pos, std::string& remainingString, ValueType valueCopy, Node* oldNodeEdges[] = nullptr); //insert pair when no prefixes are present in the tree
    void insertBeyondRoot(Node* currentNode, std::string& remainingString, ValueType valueCopy);
    void destroyNode(Node* node);
    
};

template <typename ValueType>
RadixTree<ValueType>::RadixTree()
{
    for (int i = 0; i < 128; i++)
        m_root[i] = nullptr;
    m_currNode = nullptr;
}

template <typename ValueType>
RadixTree<ValueType>::~RadixTree(){}


template <typename ValueType>
RadixTree<ValueType>::~RadixTree()
{
    for (int i = 0; i < 128; i++)
    {
        if (m_root[i] != nullptr)
            destroyNode(m_root[i]);
    }
}



template <typename ValueType>
void RadixTree<ValueType>::destroyNode(Node* node)
{
    for (int i = 0; i < 128; i++)
    {
        if (node->edges[i] != nullptr)
        {
            destroyNode(node->edges[i]);
        }
    }
    delete node;
}





template <typename ValueType>
void RadixTree<ValueType>::insert(std::string key, const ValueType &value)
{
    
    std::string remainingString = key;
    if (m_root[remainingString[0]] == nullptr) //No prefixes in radix tree at all
    {
        insertNoMorePrefixes(m_root, remainingString[0], remainingString, value);
        return;
    }
    
    else
    {
        m_currNode = m_root[remainingString[0]];
        insertBeyondRoot(m_currNode, remainingString, value);
       
    }
    
}

//function to insert pair when no more prefixes remain in tree
template <typename ValueType>
void RadixTree<ValueType>::insertNoMorePrefixes(Node* arr[], int pos, std::string& remainingString, ValueType valueCopy, Node* oldNodeEdges[])
{
    remainingString.erase(0, 1);
    arr[pos] = new Node(remainingString, valueCopy, oldNodeEdges);
    return;
}

template <typename ValueType>
void RadixTree<ValueType>::insertBeyondRoot(Node* currentNode, std::string& remainingString, ValueType valueCopy)
{
    Node* currNode = currentNode;
    
    remainingString.erase(0, 1);
    
    if (remainingString == "" && currNode->endOfWord == false) //just added second condition
    {
        currNode->endOfWord = true;
        currNode->nValue = valueCopy;
        return;
    }
    
    if (currNode->nString == "" && currNode->edges[remainingString[0]] == nullptr && remainingString.size() != 1 && currNode->endOfWord == false) //RECENTLY CHANGED; last && was added
    {
        
        currNode->nString = remainingString;
        currNode->endOfWord = true;
        currNode->nValue = valueCopy;
        remainingString = "";
    
        return;
    }
    
    //should take us to the first node that contains a nString value containing at least 1 character, return if we never come across such a node
    while (currNode->nString == "" && currNode->edges[remainingString[0]] != nullptr)
    {
        currNode = currNode->edges[remainingString[0]];
        remainingString.erase(0, 1);
        if (remainingString.size() == 0)
        {
            currNode->endOfWord = true;
            currNode->nValue = valueCopy;
            return;
        }
    }
    
    //compare remainingString and string value contained in node
    int biggerStringSize;
    if (remainingString.size() > currNode->nString.size())
        biggerStringSize = remainingString.size();
    else
        biggerStringSize = currNode->nString.size();
    
    for (int i = 0; i < biggerStringSize + 1 ; i++)
    {
        
        //if first character of remaining string is included in prefix, move on to next character of remaining string
        if (remainingString != "" && remainingString[0] == currNode->nString[i])
        {
            remainingString.erase(0, 1);
            continue;
        }
        
        //remaining string and prefix perfectly match
        if (remainingString.size() == 0 && currNode->nString.size() == i) //is this right?
        {
            currNode->nValue = valueCopy;
            currNode->endOfWord = true;
            return;
        }
        
        //remainingString included fully in prefix but prefix extends beyond remainingString
        if (remainingString.size() == 0 && currNode->nString.size() > i)
        {
            
            std::string oldNString = currNode->nString;
            std::string excessnString = oldNString;
            excessnString.erase(0, i); //should it be i - 1?
            std::string excessnStringCopy = excessnString; //to have access to value as it is after insertNoMorePrefixes func. changes it
            
            std::string newNString = oldNString;
            newNString.erase(i, oldNString.size() - i);
            currNode->nString = newNString;
            
            ValueType tempVal = currNode->nValue;
            currNode->nValue = valueCopy;
            currNode->endOfWord = true;
       
            insertNoMorePrefixes(currNode->edges, excessnString[0], excessnString, tempVal, currNode->edges);
            for (int i = 0; i < excessnStringCopy[0]; i++)
                currNode->edges[i] = nullptr;
            for (int i = excessnStringCopy[0] + 1; i < 128; i++)
                currNode->edges[i] = nullptr;
            return;
            
        }
        
        //prefix included fully in remaining string but remaining string extends beyond prefix
        if (remainingString.size() > 0 && currNode->nString.size() == i) //SHOULD IT BE <= I? <I?
        {
            if (currNode->edges[remainingString[0]] == nullptr)
            {
                char tempChar = remainingString.at(0);
                remainingString.erase(0, 1);
                currNode->edges[tempChar] = new Node(remainingString, valueCopy); //NEW
              //  insertBeyondRoot(currNode->edges[remainingString[0]], remainingString, valueCopy);
                return;
            }
            insertBeyondRoot(currNode->edges[remainingString[0]], remainingString, valueCopy);
            return;
        }
        
        //mismatch
        if (remainingString[0] != currNode->nString[i])
        {
           // newVal1 will be the one with the copied over array
                       
            std::string commonPrefix = currNode->nString.substr(0, i);
            int cutoffPoint = commonPrefix.size();
            
            std::string newString1 = currNode->nString;
            newString1.erase(0, cutoffPoint);
            std::string newString2 = remainingString;
            
            //create copies to remember newStrings as they are now, before call to insertNoMorePrefixes functions manipulate them; doing this is necessary for setting the node's array of pointers appropriately after the two new nodes are created
            std::string newString1Copy = newString1;
            std::string newString2Copy = newString2;

            currNode->endOfWord = false;
            currNode->nString = commonPrefix;
            
            insertNoMorePrefixes(currNode->edges, newString1[0], newString1, currNode->nValue, currNode->edges);
            insertNoMorePrefixes(currNode->edges, newString2[0], newString2, valueCopy); //make sure valueCopy is the right value to insert
            
            //set node's array properly (new nodes pointed to, every other slot nullptr)
            bool string1LessThanString2 = newString1Copy < newString2Copy;
            if (string1LessThanString2)
            {
                for (int i = 0; i < newString1Copy[0]; i++)
                    currNode->edges[i] = nullptr;
                for (int j = newString1Copy[0] + 1; j < newString2Copy[0]; j++)
                    currNode->edges[j] = nullptr;
                for (int k = newString2Copy[0] + 1; k < 128; k++)
                    currNode->edges[k] = nullptr;
                return;
            }
            else
            {
                for (int i = 0; i < newString2Copy[0]; i++)
                    currNode->edges[i] = nullptr;
                for (int j = newString2Copy[0] + 1; j < newString1Copy[0]; j++)
                    currNode->edges[j] = nullptr;
                for (int k = newString1Copy[0] + 1; k < 128; k++)
                    currNode->edges[k] = nullptr;
                return;
            }
        }
    }
}




template <typename ValueType>
ValueType* RadixTree<ValueType>::search(std::string key) const
{
    Node* currNode = nullptr;
    std::string remainingKey = key;
    
    if (m_root[remainingKey[0]] == nullptr)
        return nullptr;
    currNode = m_root[remainingKey[0]];
    remainingKey.erase(0, 1);
    
    while (remainingKey.size() >= 0)
    {
        if (remainingKey.size() == 0 && currNode->endOfWord == true)
            return &currNode->nValue;
        if (remainingKey.size() == 0 && currNode->endOfWord == false)
            return nullptr;

        if (currNode->nString == "")
        {
            if (currNode->edges[remainingKey[0]] == nullptr)
                return nullptr;
            else
            {
                currNode = currNode->edges[remainingKey[0]];
                remainingKey.erase(0, 1);
                continue;
            }
        }
        
        if (currNode->nString.size() > 0)
        {
            for (int i = 0; i < currNode->nString.size(); i++)
            {
                if (remainingKey.size() > 0 && remainingKey[0] == currNode->nString[i])
                {
                    remainingKey.erase(0, 1);
                }
            }
            if (remainingKey.size() == 0)
                continue;
            if (currNode->edges[remainingKey[0]] == nullptr)
                return nullptr;
            currNode = currNode->edges[remainingKey[0]];
          //  if (currNode->nString.size() != 1)
                remainingKey.erase(0, 1);
            continue;
        }

    }
    return nullptr;
}

#endif //RADIXTREE

*/
