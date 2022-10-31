#include <iostream>
#include "RadixTreeTest.h"
using namespace std;

int main()
{
    RadixTree<std::string> stringTree;
    stringTree.insert("h", "There"); // case 1
    stringTree.insert("h", "Therererererer"); // case 2
    stringTree.insert("hit", "point"); // case 2
    stringTree.insert("hips", "value 1"); // case 2
    stringTree.insert("hipster", "value 2"); // case 2
    stringTree.insert("hipsters", "value 3"); // case 2
    stringTree.insert("diabolical", "value 4"); // case 1
    stringTree.insert("diabolica", "value 5"); // case 3
    stringTree.insert("diary", "worked!"); // case 3
    stringTree.insert("d", "value 6"); // case 4
    stringTree.insert("hip", "value 7"); // case 5
    
    std::string test = *stringTree.search("h");
    std::string test2 = *stringTree.search("h");
    std::string test3 = *stringTree.search("hit");
    std::string test4 = *stringTree.search("hips");
    std::string test5 = *stringTree.search("hipster");
    std::string test6 = *stringTree.search("hipsters");
    std::string test7 = *stringTree.search("diabolical");
    std::string test8 = *stringTree.search("diabolica");
    std::string test9 = *stringTree.search("d");
    std::string test10 = *stringTree.search("hip");




    cout << test << endl << test2 << endl << test3 << endl << test4 << endl << test5 << endl << test6 << endl << test7 << endl << test8 << endl << test9 << endl << test10 << endl;
 //   if (test3 == nullptr)
        cout << "Let's go!" << endl;
}
