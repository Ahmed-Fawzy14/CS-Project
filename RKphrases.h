#pragma once
#include "RabinKarp.h"
#include "File.h"


class Phrases : public RabinKarp {
public:
	int numberOfPhrases(int length, int phrases);
	unordered_map<string, string> rabinKarpPolyPhrases(string main, string c1, string c2, string c3, int words);
	unordered_map<string, string> rabinKarpFingerPrintPhrases(string main, string c1, string c2, string c3, int words);


};