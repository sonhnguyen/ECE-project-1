#include <iostream>
#include <string>
using namespace std;
using std::string;
#pragma once

bool *IntToBinary(unsigned int i);

string BinToNumber(bool * a);
int BinToInt(bool * a);
string Pow2(int pow);

string Plus2String(string num1, string num2);
string Plus2BinaryString(string bin1, string bin2);
void output(bool*a);