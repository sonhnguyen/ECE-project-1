#include "QInt.h"
#include "1251049.h"
using namespace std;
void main()
{
	QInt a = QInt("1101101010111110111111");
	a.PrintOutInBinary();
	//a.PrintOutInDecimal();
	bool * b = new bool[128];
	b = a.ToBinary();
	cout << BinToNumber(b);
}