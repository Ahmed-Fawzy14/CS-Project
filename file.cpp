#include <fstream>
#include <string>
#include "File.h"
using namespace std;

template <>
string file<string>::readFile() const
{
	return "Ahmed";
}