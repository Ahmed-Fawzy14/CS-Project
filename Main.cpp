#include<iostream>
#include<unordered_set>
#include "File.h"
#include "RabinKarp.h"
#include "RKphrases.h"
#include "RKsentences.h"
#include "Main.h"

using namespace std;

float jaccardSimilarity(const unordered_set<string>& set1, const unordered_set<string>& set2) {
    unordered_set<string> intersection;
    unordered_set<string> unionSet;

    // Calculate intersection
    for (const auto& ngram : set1) {
        if (set2.count(ngram) > 0) {
            intersection.insert(ngram);
        }
    }

    // Calculate union
    unionSet = set1;
    for (const auto& ngram : set2) {
        unionSet.insert(ngram);
    }

    float jaccard = static_cast<float>(intersection.size()) / unionSet.size();

    return jaccard;
}

//Get N-Grams for Jaccard
vector<string> generateNGrams(const string& str, int n) {
    vector<string> ngrams;
    for (int i = 0; i <= str.length() - n; i++) {
        ngrams.push_back(str.substr(i, n));
    }
    return ngrams;
}

//Calculates the percentage of similarity in the corpus vs the main using Jaccard Similarity 
void similarityPercent(string main, string c1, string c2, string c3) {

    vector<string> suspiciousNGrams = generateNGrams(main, 5);
    std::unordered_set<std::string> suspiciousSet(suspiciousNGrams.begin(), suspiciousNGrams.end());

    vector<string> referenceNGrams = generateNGrams(c1, 5);
    std::unordered_set<std::string> referenceSet(referenceNGrams.begin(), referenceNGrams.end());
    //a lot of plagarism trace it 
    float similarity = jaccardSimilarity(suspiciousSet, referenceSet);
    if (similarity >= 0.5) {
        cout << "Similarity of: " << similarity * 100 << "% suggests plagarism";
    }
    else if (similarity <= 0.5 && similarity >= 25) {
        cout << "Similarity of: " << similarity * 100 << "% is slightly high";
    }
    else
        cout << "No Plagarism";

}


void runProgram() {

    //objects
    Phrases p;
    Sentences s;

    //maps
    unordered_map<string, string> found = {};
    unordered_map<string, string> foundPoly4Phrases = {};
    unordered_map<string, string> foundPoly3Phrases = {};
    unordered_map<string, string> foundPoly2Phrases = {};
    unordered_map<string, string> foundPolySentences = {};



    //files
    ifstream c1F("Corp1.txt");
    string c1 = p.readFile(&c1F);

    ifstream c2F("c2.txt");
    string c2 = p.readFile(&c2F);

    ifstream c3F("c3.txt");
    string c3 = p.readFile(&c3F);

    ifstream infile("Sus.txt");
    string main = p.readFile(&infile);



    //found = rabinKarp(main, c1, c2, c3);

    foundPoly4Phrases = p.rabinKarpPolyPhrases(main, c1, c2, c3, 4);
    foundPoly3Phrases = p.rabinKarpPolyPhrases(main, c1, c2, c3, 3);
    foundPoly2Phrases = p.rabinKarpPolyPhrases(main, c1, c2, c3, 2);
    //still need to fix in sentences
    foundPolySentences = s.rabinKarpPolySentences(main, c1, c2, c3);


    //fingerprint
    //figure out how to writw this normally 
    /* for (auto it = found.begin(); it != found.end(); it++) {
         cout << it->first << '\t' << it->second << endl;

     }*/


     //need to create a print function
    //foundPolyPhrases print 
      for (auto it = foundPoly4Phrases.begin(); it != foundPoly4Phrases.end(); it++) {
          cout << it->first << '\t' << it->second << endl;

      }

      for (auto it = foundPoly3Phrases.begin(); it != foundPoly3Phrases.end(); it++) {
          cout << it->first << '\t' << it->second << endl;

      }

      for (auto it = foundPoly2Phrases.begin(); it != foundPoly2Phrases.end(); it++) {
          cout << it->first << '\t' << it->second << endl;

      }

      //foundPolySentences print 
      for (auto it = foundPolySentences.begin(); it != foundPolySentences.end(); it++) {
          cout << it->first << '\t' << it->second << endl;

      }

      similarityPercent(main, c1, c2, c3);

      //Now I have:
      //Jaccard sim working but i need to understand it
      //RK is working with the things need to find a nice way to priont 
      // loop i think is solved
      //multiple docs either need to be the same size or I would need to use seperate fucntion or smth else idk yet
  

}





