#pragma once
#include "RabinKarp.h"
#include "File.h"




class Sentences : public RabinKarp{
public:
	int numberOfSentences(string str);
	unordered_map<string, string> rabinKarpPolySentences(string main, string c1, string c2, string c3);
	unordered_map<string, string> rabinKarpFingerPrintSentences(string main, string c1, string c2, string c3);
};