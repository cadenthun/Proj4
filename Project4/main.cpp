//main.cpp

#include "PersonProfile.h"
#include "RadixTree.h"
#include "AttributeTranslator.h"
#include "MemberDatabase.h"
#include "MatchMaker.h"
#include "provided.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void listCompatiblePairs(const AttributeTranslator& translator) { //get rid of this later
 AttValPair att("hobby", "chess");
 std::vector<AttValPair> result =
 translator.FindCompatibleAttValPairs(att);
if (!result.empty()) {
 std::cout << "Compatible attributes and values:" << std::endl;
 for (const auto& p: result)
 std::cout << p.attribute << " -> " << p.value << std::endl;
 }
}



/*
const std::string MEMBERS_FILE    = "members.txt";
const std::string TRANSLATOR_FILE = "translator.txt";

bool findMatches(const MemberDatabase& mdb, const AttributeTranslator& at);
*/
/*
int main() {
    MemberDatabase mdb;
    if (!mdb.LoadDatabase(MEMBERS_FILE))
    {
        std::cout << "Error loading " << MEMBERS_FILE << std::endl;
        return 1;
    }
    AttributeTranslator at;
    if (!at.Load(TRANSLATOR_FILE))
    {
        std::cout << "Error loading " << TRANSLATOR_FILE << std::endl;
        return 1;
    }

    while (findMatches(mdb, at))
        ;

    std::cout << "Happy dating!" << std::endl;
}

bool findMatches(const MemberDatabase& mdb, const AttributeTranslator& at)
{
      // Prompt for email
    std::string email;
    const PersonProfile* pp;
    for (;;) {
        std::cout << "Enter the member's email for whom you want to find matches: ";
        std::getline(std::cin, email);
        if (email.empty())
            return false;
        pp = mdb.GetMemberByEmail(email);
        if (pp != nullptr)
            break;
        std::cout << "That email is not in the member database." << std::endl;
    }

      // Show member's attribute-value pairs
    std::cout << "The member has the following attributes:" << std::endl;
    for (int k = 0; k != pp->GetNumAttValPairs(); k++) {
        AttValPair av;
        pp->GetAttVal(k, av);
        std::cout << av.attribute << " --> " << av.value << std::endl;
    }

      // Prompt user for threshold
    int threshold;
    std::cout << "How many shared attributes must matches have? ";
    std::cin >> threshold;
    std::cin.ignore(10000, '\n');

      // Print matches and the number of matching translated attributes
    MatchMaker mm(mdb, at);
    std::vector<EmailCount> emails = mm.IdentifyRankedMatches(email, threshold);
    if (emails.empty())
        std::cout << "No member was a good enough match." << std::endl;
    else {
        std::cout << "The following members were good matches:" << std::endl;;
        for (const auto& emailCount : emails) {
            const PersonProfile* pp = mdb.GetMemberByEmail(emailCount.email);
            std::cout << pp->GetName() << " at " << emailCount.email << " with "
                      << emailCount.count << " matches!" << std::endl;
        }
    }
    std::cout << std::endl;
    return true;
}
*/

int main()
{
    //test for FindMatchingMembers
    
    MemberDatabase a;
    a.LoadDatabase("/Users/cadenthun/Downloads/Unhinged/Members.txt");
    AttValPair att("trait", "weak");
    vector<string> b = a.FindMatchingMembers(att);
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << endl;
    
    
    
    
    //PersonProfile tests
    /*
    PersonProfile testProf("Caden", "c@gmail.com");
    AttValPair pair1("favorite sport", "basketball");
    AttValPair pair2("least favorite sport", "swimming");
    AttValPair pair3("hobby", "reading");
    testProf.AddAttValPair(pair1);
    testProf.AddAttValPair(pair2);
    testProf.AddAttValPair(pair3);
    cout << "Number of Pairs: " << testProf.GetNumAttValPairs() << endl;
    for (int k = 0; k != testProf.GetNumAttValPairs(); k++) {
     AttValPair av;
     testProf.GetAttVal(k, av);
     cout << av.attribute << " -> " << av.value << std::endl;
     }
    AttValPair bv;
    cout << testProf.GetAttVal(1, bv) << endl;
    cout << bv.attribute << " -> " << bv.value << std::endl;
     */
    
    AttributeTranslator c;
    c.Load("/Users/cadenthun/Downloads/Unhinged/translator.txt");
 //   listCompatiblePairs(c);
   // c.FindCompatibleAttValPairs(const AttValPair& source)
}
