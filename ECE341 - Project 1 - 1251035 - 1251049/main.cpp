#include "QInt.h"
#include "Lib.h"
using namespace std;

void main()
{
	ofstream outfile;
	outfile.open("output.txt");
	ifstream infile;
	infile.open("input.txt");

	if (infile.is_open())
	{
		string line;
		while (getline(infile, line))
		{
			outfile << resultFromLine(line) << endl;
		}
		infile.close();
	}

}