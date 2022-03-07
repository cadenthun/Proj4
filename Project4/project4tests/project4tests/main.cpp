#include <iostream>
#include <string>
using namespace std;


int convertedChar(char c) //converts char into an int between 0 and 180
{
    return c - 'a';
}

int main()
{
    string a = "hello";
    a.erase(0, 1);
    cout << a << endl;
    int b = convertedChar('%');
    cout << b << endl;
}



/*
 #ifndef RADIXTREE
 #define RADIXTREE

 #include <iostream>
 #include <string>

 template <typename ValueType>
 class RadixTree {
     
 public:
  RadixTree();
  ~RadixTree();
  void insert(std::string key, const ValueType& value);
 ValueType* search(std::string key) const;
     
 private: //get rid of this once I implement the Radix Tree
   //  std::unordered_map<std::string, ValueType> m_tempMap;
     bool m_empty = true; //HAVE TO CHANGE THIS TO FALSE AS SOON AS A NODE GETS ADDED
     struct Node
     {
         std::string nodeString;
         Node* edges[128];
         ValueType* nodeValuePtr;
         bool endOfWord;
         Node (std::string nString = "")
         {
             for (int i = 0; i < 128; i++)
                 edges[i] = nullptr;
             nodeString = nString;
         }
         Node (ValueType nValue, std::string nString = "") //inserting a leaf node containing a value
         {
             nodeValuePtr = &nValue;
             nodeString = nString;
             endOfWord = true;
         }
     };
     Node* m_root[128] = {nullptr};
 };

 template <typename ValueType>
 RadixTree<ValueType>::RadixTree()
 {
     for (int i = 0; i < 128; i++)
         m_root[i] = nullptr;
 }

 template <typename ValueType>
 RadixTree<ValueType>::~RadixTree()
 {
     
 }


 template <typename ValueType>
 void RadixTree<ValueType>::insert(std::string key, const ValueType &value)
 {
     Node* currNode = nullptr; // for navigating through tree
     
     ValueType valueCopy = value; // where nodeValuePtr will eventually point to
     
     if (m_root[key.at(0)] == nullptr) // no words in tree that begin with starting letter of insetionString
     {
         int insertionIndex = key.at(0);
         key.erase(0, 1);
         if (key.size() == 0) // key was 1 char long
         {
             m_root[insertionIndex] = new Node(valueCopy, "");
             return; // key/value pair inserted
         }
         m_root[insertionIndex] = new Node(valueCopy, key); // handle situation where key was more than 1 char long
     }
     
     else
     {
         currNode = m_root[key.at(0)];
         
         key.erase(0, 1);
         
         if (currNode->nodeString == "")
         {
             if (currNode->edges[key.at(0)] == nullptr)
             {
                 int insertionIndex = key.at(0);
                 key.erase(0, 1);
                 if (key.size() == 0) // remaining key was 1 char long
                 {
                     currNode->edges[insertionIndex] = new Node(valueCopy, "");
                     return; // 1 return condition for recursive function
                 }
                 currNode->edges[insertionIndex] = new Node(valueCopy, key); // key was more than 1 char long
             }
             else // currNode->edges[key.at(0)] != nullptr
         }
         else
         {
             // check insertionString against nodeString, handling each edge case as necessary
         }
         
         
     }
 }

 template <typename ValueType>
 ValueType* RadixTree<ValueType>::search(std::string key) const
 {
     return nullptr; //DUMMY
 }

 #endif /* RADIXTREE */
 */
