#include<iostream>
#include<unordered_set>
#include"File.h"
#include"RabinKarp.h"
using namespace std;


//reads file and returns string with file data
string RabinKarp::readFile(ifstream* infile) const {
    
        string line, temp;
    
        while (getline(*infile, temp)) { line = line + temp; }
    
        return line;
}

 //fingerprint hash
 int RabinKarp::FingerprintHashFunction(string str, long long p, long long x)
 {
     int result = 0;
     for (int i = 0; i < str.length(); i++) {
         result = (result * x + str[i]) % p;
     }
     return result;
     return 0;
 }

 //polyynomial hash

 int RabinKarp::QuadraticHashFunction(string str, long long p, long long x)
 {
     int result = 0;
     for (int i = 0; i < str.length(); i++) {
         //do not count punctuation aswell
         if (str[i] != ' ' && str[i] != '.' && str[i] != '?' && str[i] != '!' && str[i] != '(' && str[i] != ')' && str[i] != '[' && str[i] != ']' && str[i] != '\0')
             result = (result * x + str[i]) % p;
     }
     return result;
 }


 void RabinKarp::setHash(int x) {
     hash = x;
 }

 void RabinKarp::setWords(int x) {
     words = x;
 }

 void RabinKarp::setMainIndex(int x) {
     mainIndex = x;
 }

 void RabinKarp::setCorpus1Index(int x) {
    corpus1Index = x;
 }

 void RabinKarp::setCorpus2Index(int x) {
     corpus2Index = x;
 }

 void RabinKarp::setCorpus3Index(int x) {
     corpus3Index = x;
 }

 void RabinKarp::setMainIndexPrint(int x) {
     mainIndexPrint = x;
 }

 void RabinKarp::setCorpus1IndexPrint(int x) {
     corpus1IndexPrint = x;
 }

 void RabinKarp::setCorpus2IndexPrint(int x) {
     corpus2IndexPrint = x;
 }

 void RabinKarp::setCorpus3IndexPrint(int x) {
     corpus3IndexPrint = x;
 }

 void RabinKarp::setMainFile(string mainFile) {
     mainFile = mainFile;
 }

 void RabinKarp::setCorpusFile(string corpusFile) {
     corpusFile = corpusFile;
 }

 void RabinKarp::setMatch(bool match) {
     match = match;
 }

 void RabinKarp::setMainSplit(int hashValue, string mainFile) {
     mainSplit[hashValue]=mainFile;
 }

 void RabinKarp::setMainSplitPrint(int hashValue, string mainFile) {
     mainSplitPrint[hashValue]=mainFile;
 }

 void RabinKarp::setC1Split(int hashValue, string corpusFile) {
     c1Split[hashValue]=corpusFile;
 }

 void RabinKarp::setC1SplitPrint(int hashValue, string corpusFile) {
     c1SplitPrint[hashValue]=corpusFile;
 }

 void RabinKarp::setC2Split(int hashValue, string corpusFile) {
     c2Split[hashValue]=corpusFile;
 }

 void RabinKarp::setC2SplitPrint(int hashValue, string corpusFile) {
     c2SplitPrint[hashValue] = corpusFile;
 }

 void RabinKarp::setC3Split(int hashValue, string corpusFile) {
     c3Split[hashValue]=corpusFile;
 }

 void RabinKarp::setC3SplitPrint(int hashValue, string corpusFile) {
     c3SplitPrint[hashValue]=corpusFile;
 }

 void RabinKarp::setFound(string corpusFile, string mainFile) {
     found[corpusFile] = mainFile;
 }


 int RabinKarp::getHash() const {
     return hash;
 }

 int RabinKarp::getWords() const {
     return words;
 }

 int RabinKarp::getMainIndex() const {
     return mainIndex;
 }

 int RabinKarp::getCorpus1Index() const {
     return corpus1Index;
 }

 int RabinKarp::getCorpus2Index() const {
     return corpus2Index;
 }

 int RabinKarp::getCorpus3Index() const {
     return corpus3Index;
 }

 int RabinKarp::getMainIndexPrint() const {
     return mainIndexPrint;
 }

 int RabinKarp::getCorpus1IndexPrint() const {
     return corpus1IndexPrint;
 }

 int RabinKarp::getCorpus2IndexPrint() const {
     return corpus2IndexPrint;
 }

 int RabinKarp::getCorpus3IndexPrint() const {
     return corpus3IndexPrint;
 }

 string RabinKarp::getMainFile() const {
     return mainFile;
 }

 string RabinKarp::getCorpusFile() const {
     return corpusFile;
 }

 bool RabinKarp::getIsMatch() const {
     return isMatch;
 }

 unordered_map<int, string> RabinKarp::getMainSplit() const {
     return mainSplit;
 }

 unordered_map<int, string> RabinKarp::getMainSplitPrint() const {
     return mainSplitPrint;
 }

 unordered_map<int, string> RabinKarp::getC1Split() const {
     return c1Split;
 }

 unordered_map<int, string> RabinKarp::getC1SplitPrint() const {
     return c1SplitPrint;
 }

 unordered_map<int, string> RabinKarp::getC2Split() const {
     return c2Split;
 }

 unordered_map<int, string> RabinKarp::getC2SplitPrint() const {
     return c2SplitPrint;
 }


 unordered_map<int, string> RabinKarp::getC3Split() const {
     return c3Split;
 }

 unordered_map<int, string> RabinKarp::getC3SplitPrint() const {
     return c3SplitPrint;
 }


 unordered_map<string, string> RabinKarp::getFound() const {
     return found;
 }

 string RabinKarp::removeSpaces(string str, int& i, int words) const
 {
     int x = 0;
     string sub{};
     char c;

     while (x < words && i <= str.length()) {
         if (str[i] == ' ' && str[i + 1] != ' ') {
             x++;
             i++;
         }
         else {
             c = tolower(str[i]);
             sub = sub + c;
             i++;

         }

     }

     return sub;

 }


 string RabinKarp::removeSpaces(string str, int& i) const
 {
     int x = 0;
     string sub{};
     char c;

     //when meeting punctuation counting the word after as a word if no space? "i am amazing.ahmed vs i am amazing. Ahmed

     //now i am trying to detect by sentences 

     //check using the words var multiple word size and sentences to increase chance of finding smth
     //we need to comine both algorithms to have the best chance of detecitng plagarism 
     //combine sentences with phrases 
     while (x < 1) {

         if (str[i] == ' ' && str[i + 1] != ' ') {
             i++;
         }
         if (str[i] == '.' || str[i] == '?' || str[i] == ',' || str[i] == ';' || str[i] == '!')
         {
             x++;
             c = tolower(str[i]);
             sub = sub + c;
             i++;
         }

         else
         {

             c = tolower(str[i]);
             sub = sub + c;
             i++;
         }
     }

     return sub;

 }




 //Generate custom substrings using phrases

 string RabinKarp::calcBound(string str, int& i, int words) const
 {
     int x = 0;
     string sub{};
     char c;

     //when meeting punctuation counting the word after as a word if no space? "i am amazing.ahmed vs i am amazing. Ahmed

     while (x < words && i <= str.length()) {
         if (str[i] == ' ' && str[i + 1] != ' ')
         {
             x++;
             c = tolower(str[i]);
             sub = sub + c;
             i++;
         }

         else
         {

             c = tolower(str[i]);
             sub = sub + c;
             i++;
         }
     }



     return sub;
 }

 //Generate custom substrings using sentences

 string RabinKarp::calcBound(string str, int& i) const
 {
     int x = 0;
     string sub{};
     char c;


     while (x < 1) {
         if (str[i] == '.' || str[i] == '?' || str[i] == ',' || str[i] == ';' || str[i] == '!')
         {
             x++;
             c = tolower(str[i]);
             sub = sub + c;
             i++;
         }

         else
         {

             c = tolower(str[i]);
             sub = sub + c;
             i++;
         }
     }



     return sub;
 }
