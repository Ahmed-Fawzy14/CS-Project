#pragma once
#include <fstream>
#include <string>
using namespace std;

template <typename T>
class file {
protected:
	//ifstream objects 
	ifstream file_x;
	ifstream file_y;

public:
	//Read characters from file and return either a string or a stirng vector
	virtual T readFile() const;
	//returns ifstream objects 
	ifstream&  getFile_x () const;
	ifstream&  getFile_y () const;
	//Creates and opens sent file name
	void setFile_x(string fileName);
	void setFile_y(string fileName);
};

