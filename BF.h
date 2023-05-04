#pragma once
#include"File.h"
#include <string>
#include <unordered_map>
#include <vector>







template <typename T>
class brute_force :public file<T>
{
private:
	struct index
	{
		int sentence_x, sentence_y, index_x, index_y;
	};

	vector<char> filex, filey;
	vector<index>plagiarised_sentences;
	int threshold;
public:



	brute_force(string xfilename, string yfilename, int t);
	void readFile();
	bool ishamming(string a, string b);
	int brute_check(vector<char> txt2, vector<char> txt);
	vector<char> const getsentence_filex(int i);
	vector<char> const getsentence_filey(int i);
	int const number_of_phrases_filex();
	int const number_of_phrases_filey();
	void push_plagiarized_indexes(int sentencex, int sentencey, int index_x, int index_y);
	index const getIndex(int ind);
	vector<char> const getfilexvector();
	vector<char> const getfileyvector();


};








