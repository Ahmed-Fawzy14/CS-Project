#pragma once
#include <fstream>
#include <string>

template <typename T>
class file {
protected:
	//ifstream file_x;
	//ifstream file_y;

public:

	virtual T readFile() const;
	//ifstream& const getFile_x();
	//ifstream& const getFile_y();
	//void setFile_x(string fileName);
	//void setFile_y(string fileName);
};

