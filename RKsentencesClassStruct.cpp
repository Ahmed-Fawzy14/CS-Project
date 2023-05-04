
#include "RKsentences.h"
using namespace std;


int Sentences::numberOfSentences(string str)
{
    int sentences = 0;
    //COUNT PUNCTUATION MARKS
    string sub{};
    char c;
    int i = 0;

    //when meeting punctuation counting the word after as a word if no space? "i am amazing.ahmed vs i am amazing. Ahmed

    //now i am trying to detect by sentences 

    //check using the words var multiple word size and sentences to increase chance of finding smth
    //we need to comine both algorithms to have the best chance of detecitng plagarism 
    //combine sentences with phrases 
    for (int i = 0; i < str.length(); i++) {

        if (str[i] == '.' || str[i] == '?' || str[i] == ',' || str[i] == ';' || str[i] == '!')
        {
            sentences++;
        }

    }


    return sentences;
}

unordered_map<string, string> Sentences::rabinKarpPolySentences(string main, string c1, string c2, string c3)
{
  
        unordered_map<int, string> mainSplit{};
        unordered_map<int, string> mainSplitPrint{};
    
        unordered_map<int, string> c1Split{};
        unordered_map<int, string> c1SplitPrint{};
    
        unordered_map<int, string> c2Split{};
        unordered_map<int, string> c3Split{};
        int hash;
        unordered_map<string, string> found{};
    
    
        //need to pass this from main input from user
        int words = 3;
        int mainIndex = 0;
        int corpus1Index = 0;
        int mainIndexPrint = 0;
        int corpus1IndexPrint = 0;
        //int corpus2Index = 0;
        //int corpus3Index = 0;
        int n = main.length();
        int m = c1.length();
        int l = 0;
        string longer{};
    
        if (m > n)
            longer = main;
        else
            longer = c1;
        //need it to run one more time it stops a sentecne short
        for (int i = 0; i < numberOfSentences(longer); i++)
        {
    
            //by spliting into 3 words we have something ok but still needs impvrments against random spacing and deletion of words
            // space  still fucks and tarteeb
            //also if docs are not the same number of words I will need to use seperate funcitons
            string mSub = removeSpaces(main, mainIndex);
            string c1Sub = removeSpaces(c1, corpus1Index);
            string mSubPrint = calcBound(main, mainIndexPrint);
            string c1SubPrint = calcBound(c1, corpus1IndexPrint);
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
    
        //i think it works
        string temp1{};
        string temp2{};
        bool match1 = true;
        //bool match2 = true;
        //bool match3 = true;
        for (auto it = mainSplit.begin(); it != mainSplit.end(); it++) {
            if (c1Split.count(it->first)) {
                match1 = true;
                //temp1 = (it->second).substr(0, (it->second).size() - 1);
                //temp2 = (c1Split[it->first]).substr(0, (c1Split[it->first]).size() - 1);;
                if (it->second != c1Split[it->first]) {
                    match1 = false;
                }
    
                else
                {
                    if (match1 == true) {
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

unordered_map<string, string> Sentences::rabinKarpFingerPrintSentences(string main, string c1, string c2, string c3)
{
    return found;
}