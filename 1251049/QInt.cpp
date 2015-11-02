#include "QInt.h"
#include "1251049.h"
QInt::QInt()
{
}


QInt::~QInt()
{
}

QInt::QInt(bool * a)
{
	bool *b = new bool[32];
	for (int i = 127; i >= 96; i--){
		b[i - 96] = a[i];
	}
	arrayBits[0] = BinToInt(b); 
	for (int i = 95; i >= 64; i--){
		b[i - 64] = a[i];
	}
	arrayBits[1] = BinToInt(b);
	for (int i = 63; i >= 32; i--){
		b[i - 32] = a[i];
	}
	arrayBits[2] = BinToInt(b);
	for (int i = 31; i >= 0; i--){
		b[i] = a[i];
	}
	arrayBits[3] = BinToInt(b);
}
QInt::QInt(string a)
{
	if (a.length() > 128)
		return;
	if (a.length() < 128)
	{
		int diff = 128 - a.length();
		for (int i = 0; i < diff; i++)
		{
			a.push_back(a[a.length() - 1]);
		}
		for (int j = a.length() - 1; j >=diff; j--)
		{
			a[j] = a[j - diff];
		}
		for (int i = 0; i < diff; i++)
		{
			a[i] = '0';
		}
	}
	bool *b = new bool[128];
	for (int i = 127; i >= 0; i--)
	{
		b[i] = a[i] - 48;
	}
	bool *c = new bool[32];
	for (int i = 127; i >= 96; i--){
		c[i - 96] =b[i];
	}
	arrayBits[0] = BinToInt(c);
	for (int i = 95; i >= 64; i--){
		c[i - 64] = b[i];
	}
	arrayBits[1] = BinToInt(c);
	for (int i = 63; i >= 32; i--){
		c[i - 32] = b[i];
	}
	arrayBits[2] = BinToInt(c);
	for (int i = 31; i >= 0; i--){
		c[i] = b[i];
	}
	arrayBits[3] = BinToInt(c);
}
void QInt::SetArrayBits(int pos, bool bit)
{
	if (pos > 128) return;
	bool * b = new bool[32];
	b = IntToBinary(arrayBits[(int)(pos / 4)]);
	b[pos % 4] = bit;
	arrayBits[(int)(pos / 4)] = BinToInt(b);
}
void QInt::PrintOutInBinary()
{
	bool * a = new bool[128];
	a = ToBinary();
	string s;
	for (int i = 0; i <= 127; i++)
	{
		s.push_back(a[i] + 48);
	}
	int start = 0;
	while (s[start] == '0')
		start++;
	cout << s.substr(start)<< endl;
}
void QInt::PrintOutInDecimal()
{
	bool * a = new bool[128];
	a = ToBinary();
	cout << BinToNumber(a) << endl;
}
bool * QInt::ToBinary()
{
	bool *result = new bool[128];
	bool * b = new bool[32];
	b = IntToBinary(arrayBits[0]);
	for (int i = 127; i >= 96; i--)
	{
		result[i] = b[i-96];
	}
	b = IntToBinary(arrayBits[1]);
	for (int i = 95; i >= 64; i--)
	{
		result[i] = b[i - 64];
	}
	b = IntToBinary(arrayBits[2]);
	for (int i = 63; i >= 32; i--)
	{
		result[i] = b[i - 32];
	}
	b = IntToBinary(arrayBits[3]);
	for (int i = 31; i >= 0; i--)
	{
		result[i] = b[i];
	}
	return result;
}

QInt QInt::operator+(const QInt& other)
{
	return QInt(BinToNumber(Plus2BinaryString(BinToNumber(ToBinary()), BinToNumber(other.ToBinary()))));
}