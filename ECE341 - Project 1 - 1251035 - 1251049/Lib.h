#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <fstream>
#include <vector>
#include "QInt.h"
using namespace std;
using std::string;
#pragma once

string resultFromLine(string line);
bool *IntToBinary(unsigned int i);

string BinToNumber(bool * a);
int BinToInt(bool * a);
string Pow2(int pow);
string BoolToBin(bool * a);
bool *BinToBool(string bin);
string Plus2String(string num1, string num2);
string Plus2BinaryString(string bin1, string bin2);
void output(bool*a);
bool* HexToBin(const string& s);

string Substract2BinaryString(string bin1, string bin2);
string Multiply2BinaryString(string bin1, string bin2);

string Divide2BinaryString(string bin1, string bin2);
string RemoveLeadingZeroes(string bin);
int Bin1CompareBin2(string bin1, string b2);
string BinToHex(bool *a);