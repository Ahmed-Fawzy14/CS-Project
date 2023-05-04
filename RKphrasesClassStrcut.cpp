#include "RKphrases.h"
using namespace std;





int Phrases::numberOfPhrases(int length, int phrases)
{
    //# of words/phrases

    int number = 0;
    number = (length / phrases) + 1;

    return number;
}




unordered_map<string, string> Phrases::rabinKarpPolyPhrases(string main, string c1, string c2, string c3, int words)
{
    unordered_map<int, string> mainSplit{};
    unordered_map<int, string> mainSplitPrint{};


    unordered_map<int, string> c1Split{};
    unordered_map<int, string> c1SplitPrint{};

    unordered_map<int, string> c2Split{};
    unordered_map<int, string> c3Split{};
    int hash;
    unordered_map<string, string> found{};

    vector<string> ngMain;
    vector<string> ngCorpus_1;
    //need to pass this from main input from user
    int mainIndex = 0;
    int corpus1Index = 0;
    int mainIndexPrint = 0;
    int corpus1IndexPrint = 0;
    //int corpus2Index = 0;
    //int corpus3Index = 0;
    int n = main.length();
    int m = c1.length();
    int l = 0;

    if (m > n)
        l = m;
    else
        l = n;

    //need to find proper loop parameter maybe a while
    //numberofphrases 2,3,4

    for (int i = 0; i <= numberOfPhrases(l, words); i++)
    {

        //by spliting into 3 words we have something ok but still needs impvrments against random spacing and deletion of words
        // space  still fucks and tarteeb
        //also if docs are not the same number of words I will need to use seperate funcitons
        string mSub = removeSpaces(main, mainIndex, words);
        string c1Sub = removeSpaces(c1, corpus1Index, words);
        string mSubPrint = calcBound(main, mainIndexPrint, words);
        string c1SubPrint = calcBound(c1, corpus1IndexPrint, words);
        /* string c2Sub = calcBound(c1, corpus2Index, words);
         string c3Sub = calcBound(c1, corpus3Index, words);*/
        hash = QuadraticHashFunction(mSub, 1000000007, 263);
        mainSplit.insert({ hash, mSub });
        mainSplitPrint.insert({ hash, mSubPrint });

        c1Split.insert({ QuadraticHashFunction(c1Sub, 1000000007, 263), c1Sub });
        c1SplitPrint.insert({ QuadraticHashFunction(c1Sub, 1000000007, 263), c1SubPrint });

        /*      c1Split.insert({ polynomialRollingHash(c2Sub, 101, 257), c2Sub });
              c1Split.insert({ polynomialRollingHash(c3Sub, 101, 257), c3Sub });*/



    }



    string temp1{};
    string temp2{};
    bool match1 = true;
    //bool match2 = true;
    //bool match3 = true;
    for (auto it = mainSplit.begin(); it != mainSplit.end(); it++) {
        if (c1Split.count(it->first)) {
            match1 = true;
            temp1 = (it->second).substr(0, (it->second).size() - 1);
            temp2 = (c1Split[it->first]).substr(0, (c1Split[it->first]).size() - 1);;
            if (temp1 != temp2) {
                match1 = false;
            }

            else
            {
                if (match1 == true) {
                    //consider using emplace to insert instead of insert() b/c there maybe duplicates
                    found.insert({ c1SplitPrint[it->first] , mainSplitPrint[it->first] + "\t From Document 1 \t" });


                }

            }
        }





        //
        //if (c2Split.count(it->first)) {
        //    if (it->second != c2Split[it->first]) {
        //        match2 = false;
        //    }

        //    else
        //    {
        //        if (match2 == true) {
        //            found.insert({ c2Split[it->first] , mainSplit[it->first] + "\t From Document 2 \t" });


        //        }

        //    }
        //}
        ////
        //if (c3Split.count(it->first)) {
        //    if (it->second != c3Split[it->first]) {
        //        match3 = false;
        //    }

        //    else
        //    {
        //        if (match3 == true) {
        //            found.insert({ c3Split[it->first] , mainSplit[it->first] + "\t From Document 3 \t" });


        //        }

        //    }
        //}

    }


    //match1 = true;
    //if (it->second != c1Split[it->first]) {
    //    match1 = false;
    //}
    //else
    //{
    //    if (match1 == true) {
    //        found.insert({ c1Split[it->first] , mainSplit[it->first] + "\t From Document 1 \t" });


    //    }

    //}

    return found;
}


unordered_map<string, string> Phrases::rabinKarpFingerPrintPhrases(string main, string c1, string c2, string c3, int words)
{
	return unordered_map<string, string>();
}
