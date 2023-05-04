#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include "File.h"
using namespace std;


class RabinKarp : public file<string> {
protected:
	int hash;
	int words;
	int mainIndex;
	int corpus1Index;
	int corpus2Index;
	int corpus3Index;
	int mainIndexPrint;
	int corpus1IndexPrint;
	int corpus2IndexPrint;
	int corpus3IndexPrint;

	string mainFile;
	string corpusFile;
	bool isMatch;

	unordered_map<int, string> mainSplit{};
	unordered_map<int, string> mainSplitPrint{};
	unordered_map<int, string> c1Split{};
	unordered_map<int, string> c1SplitPrint{};
	unordered_map<int, string> c2Split{};
	unordered_map<int, string> c2SplitPrint{};
	unordered_map<int, string> c3Split{};
	unordered_map<int, string> c3SplitPrint{};
	unordered_map<string, string> found{};
public:
	//make rabinkarp and file abstract 
	virtual string readFile(ifstream* infile) const;
	int QuadraticHashFunction(string str, long long  p, long long x);
	int FingerprintHashFunction(string str, long long  p, long long x);
	string removeSpaces(string str, int& i, int words) const;
	string removeSpaces(string str, int& i) const;

	string calcBound(string str, int& i, int words) const;
	string calcBound(string str, int& i) const;

	void setHash(int x);
	void setWords(int x);
	void setMainIndex(int x);
	void setCorpus1Index(int x);
	void setCorpus2Index(int x);
	void setCorpus3Index(int x);
	void setMainIndexPrint(int x);
	void setCorpus1IndexPrint(int x);
	void setCorpus2IndexPrint(int x);
	void setCorpus3IndexPrint(int x);
	void setMainFile(string mainFile);
	void setCorpusFile(string corpusFile);
	void setMatch(bool match);
	void setMainSplit(int hashValue, string mainFile);
	void setMainSplitPrint(int hashValue, string mainFile);
	void setC1Split(int hashValue, string corpusFile);
	void setC1SplitPrint(int hashValue, string corpusFile);
	void setC2Split(int hashValue, string corpusFile);
	void setC2SplitPrint(int hashValue, string corpusFile);
	void setC3Split(int hashValue, string corpusFile);
	void setC3SplitPrint(int hashValue, string corpusFile);
	void setFound(string corpusFile, string mainFile);

	int getHash() const;
	int  getWords() const;
	int  getMainIndex() const;
	int  getCorpus1Index() const;
	int  getCorpus2Index() const;
	int  getCorpus3Index() const;
	int  getMainIndexPrint() const;
	int  getCorpus1IndexPrint() const;
	int  getCorpus2IndexPrint() const;
	int  getCorpus3IndexPrint() const;
	string  getMainFile() const;
	string  getCorpusFile() const;
	bool  getIsMatch() const;

	unordered_map<int, string>  getMainSplit() const;
	unordered_map<int, string>  getMainSplitPrint() const;
	unordered_map<int, string>  getC1Split() const;
	unordered_map<int, string>  getC1SplitPrint() const;
	unordered_map<int, string>  getC2Split() const;
	unordered_map<int, string>  getC2SplitPrint() const;
	unordered_map<int, string>  getC3Split() const;
	unordered_map<int, string>  getC3SplitPrint() const;
	unordered_map<string, string>  getFound() const;





};