#include <iostream>
#include <string>
using namespace std;
using std::string;
#pragma once
class QInt
{
public:
	QInt();
	~QInt();
	QInt(bool * a);
	QInt(string a);
	void SetArrayBits(int pos, bool bit);
	void PrintOutInBinary();
	void PrintOutInDecimal();
	bool * ToBinary();
	string ToNumber();

	QInt operator=(const QInt& other);
	QInt operator+(const QInt& other);
	QInt operator-(const QInt& other);
	QInt operator*(const QInt& other);
	QInt operator/(const QInt& other);

	QInt operator&(const QInt& other);
	QInt operator|(const QInt& other);
	QInt operator^(const QInt& other);
	QInt operator~();

	QInt operator<<(const int& i);
	QInt operator>>(const int& i);

	unsigned int arrayBits[4];
};

