#include "Lib.h"

bool *IntToBinary(unsigned int i)
{
	bool *result = new bool[32];
	int pos = 31;
	while (i > 0)
	{
		result[pos] = i % 2;
		i = i / 2;
		pos--;
	}
	while (pos >= 0)
	{
		result[pos] = 0;
		pos--;

	}
	return result;
}

string BinToNumber(bool * a)
{
	string result = "0";
	for (int i = 127; i >= 0; i--)
	{
		if (a[i] == 1)
			result = Plus2String(result, Pow2(127 - i));
	}
	return result;
}

int BinToInt(bool * a)
{
	unsigned int result = 0;
	for (int i = 31; i >= 0; i--)
	{
		if (a[i] == 1)
			result = result + pow(2, 31 - i);
	}
	return result;
}
string Pow2(int pow)
{
	string result = "1";
	while (pow > 0)
	{
		int tmp1 = 0;
		int tmp2 = 0;
		for (int i = result.length() - 1; i >= 0; i--)
		{
			if ((result[i] - 48) * 2 > 9)
			{
				tmp2 = 1;
				if (i == 0)
				{
					result.push_back(result[result.length() - 1]);
					for (int j = result.length() - 2; j > 0; j--)
					{
						result[j] = result[j - 1];
					}
					result[0] = '0';
					i++;
				}
			}
			else
			{
				tmp2 = 0;
			}
			result[i] = ((result[i] - 48) * 2) % 10 + tmp1 + 48;
			tmp1 = tmp2;
		}
		pow--;
	}
	return result;
}

string Plus2String(string num1, string num2)
{
	int diff = num1.length() - num2.length();
	if (diff > 0)
	{
		for (int i = 0; i < diff; i++)
		{
			num2.push_back(num2[num2.length() - 1]);
		}
		for (int j = num2.length() - 1 - diff; j > 0; j--)
		{
			num2[j] = num2[j - 1];
		}
		for (int i = 0; i < diff; i++)
		{
			num2[i] = '0';
		}
	}
	else if (diff<0)
	{
		diff *= -1;
		for (int i = 0; i < diff; i++)
		{
			num1.push_back(num1[num1.length() - 1]);
		}
		for (int j = num1.length() - 1 - diff; j > 0; j--)
		{
			num1[j] = num1[j - 1];
		}
		for (int i = 0; i < diff; i++)
		{
			num1[i] = '0';
		}
	}
	string result;
	for (int i = 0; i < num1.length(); i++)
	{
		result.push_back('0');
	}
	int tmp = 0;
	for (int i = num1.length() - 1; i >= 0; i--)
	{
		result[i] = ((num1[i] + num2[i] - 48 - 48) % 10) + tmp + 48;
		if (result[i] == 58)
			result[i] -= 10;
		if (num1[i] + num2[i] + tmp - 48 - 48>9)
			tmp = 1;
		else
			tmp = 0;
		if (i == 0 && tmp == 1)
		{
			result.push_back(result[result.length() - 1]);
			for (int j = result.length() - 2; j > 0; j--)
			{
				result[j] = result[j - 1];
			}
			result[0] = '1';
		}
	}
	return result;
}

void output(bool*a)
{
	for (int i = 0; i <= 31; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

string Plus2BinaryString(string bin1, string bin2)
{
	int diff = bin1.length() - bin2.length();
	if (diff<0)
	{
		diff *= -1;
		string t = bin2;
		bin2 = bin1;
		bin1 = t;
	}
	string result;
	for (int i = 0; i < bin1.length(); i++)
	{
		result.push_back('0');
	}
	int tmp = 0;
	for (int i = bin1.length() - 1; i >= 0; i--)
	{
		if (i >= diff)
		{
			result[i] = (((bin1[i] + bin2[i - diff] - 48 - 48) % 2) + tmp) % 2 + 48;
			if ((bin1[i] + bin2[i - diff] + tmp - 48 - 48)>1)
				tmp = 1;
			else
				tmp = 0;
		}
		else
		{
			result[i] = (bin1[i]-48+tmp)%2+48;
			if (bin1[i] == '1' && tmp == 1)
				tmp = 1;
			else
				tmp = 0;
		}
		if (i == 0 && tmp == 1)
		{
			result.push_back(result[result.length() - 1]);
			for (int j = result.length() - 2; j > 0; j--)
			{
				result[j] = result[j - 1];
			}
			result[0] = '1';
		}
	}
	return result;
}

string BoolToBin(bool * a)
{
	string result = "";
	for (int i = 0; i <128; i++)
	{
		if (a[i] == 1)
			result.push_back('1');
		else
			result.push_back('0');
	}
	return result;
}
bool* HexToBin(const string& s) {
	stringstream ss;
	ss << hex << s;
	unsigned n;
	ss >> n;
	bitset<32> b(n);

	unsigned x = 0;
	string result = b.to_string().substr(32 - 4 * (s.length() - x));
	bool* booleanResult = new bool[128];

	for (int i = 0; i < 128; i++) {
		booleanResult[i] = 0;
	}
	for (int i = 0; i < result.length(); i++) {
		if (result[i] == '0')
			booleanResult[128-i] = 0;
		else
			booleanResult[128-i] = 1;
	}
	return booleanResult;
}

string Substract2BinaryString(string bin1, string bin2)
{
	string t = bin2;
	int diff = bin1.length() - bin2.length();
	if (diff<0)
	{
		diff *= -1;
	}
	for (int i = 0; i < bin2.length(); i++)
	{
		if (bin2[i] == '0')
			bin2[i] = '1';
		else
			bin2[i] = '0';
	}
	bin2 = Plus2BinaryString(bin2, "1");
	string result;
	for (int i = 0; i < bin1.length(); i++)
	{
		result.push_back('0');
	}
	int tmp = 0;
	for (int i = bin1.length() - 1; i >= 0; i--)
	{
		if (i >= diff)
		{
			result[i] = (((bin1[i] + bin2[i - diff] - 48 - 48) % 2) + tmp) % 2 + 48;
			if ((bin1[i] + bin2[i - diff] + tmp - 48 - 48)>1)
				tmp = 1;
			else
				tmp = 0;
		}
		else
		{
			result[i] = (bin1[i] - 48 + tmp) % 2 + 48;
			if (bin1[i] == 1 && tmp == 1)
				tmp = 1;
			else
				tmp = 0;
		}
	}
	if (Plus2BinaryString(result, t) == bin1)
		return result;
	else
	{
		result[0] = '0';
		return RemoveLeadingZeroes(result);
	}
}

string Multiply2BinaryString(string bin1, string bin2)
{
	string result = "0";
	for (int i = bin2.length() - 1; i >= 0;i--)
	{
		if (bin2[i] == '1')
		{
			result = Plus2BinaryString(result, bin1);
		}
		bin1 = bin1 + '0';
	}
	return result;
}

string Divide2BinaryString(string bin1, string bin2)
{
	string result = "0";
	string subbin = "0";
	int cur = 0;
	int l = 0;
	while (Bin1CompareBin2(bin1,bin2) != 2)
	{
		if (Bin1CompareBin2(subbin, bin2) == 2)
		{
			subbin = bin1.substr(l, cur);
			result.push_back('0');
		}
		else
		{
			l = 0;
			result.push_back('1');
			subbin = bin2;
			int o = bin1.length() - cur + 1;
			while (o > 0)
			{
				subbin += '0';
				o--;
			}
			cur --;
			bin1 = Substract2BinaryString(bin1, subbin);
			subbin = "0";
		}
		cur++;
	}
	int o = bin1.length() - l + 1;
	while (o > 0)
	{
		result += '0';
		o--;
	}
	return RemoveLeadingZeroes(result);
}
string RemoveLeadingZeroes(string bin)
{
	int i;
	for (i = 0; bin[i] == '0'; i++);
	return  bin.substr(i, bin.length()) == "" ? "0" : bin.substr(i, bin.length());
}
int Bin1CompareBin2(string bin1, string bin2)
{
	//return 0 => bin1 = bin2
	//return 1 => bin1 > bin2
	//return 2 => bin1 < bin2
	bin1 = RemoveLeadingZeroes(bin1);
	bin2 = RemoveLeadingZeroes(bin2);
	if (bin1.length() > bin2.length())
		return 1;
	if (bin1.length() < bin2.length())
		return 2;
	for (int i = 0; i < bin1.length(); i++)
	{
		if (bin1[i] == '1' && bin2[i] == '0')
			return 1;
		if (bin2[i] == '1' && bin1[i] == '0')
			return 2;
	}
	return 0;
}


bool *BinToBool(string bin)
{
	bool* booleanResult = new bool[128];
	for (int i = 0; i < 128; i++)
		booleanResult[i] = 0;
	for (int i = 0; i < bin.length(); i++)
	{
		booleanResult[127 - i] = bin[i] == '0' ? 0 : 1;
	}
	return booleanResult;
}

string resultFromLine(string line) {
	string result;
	vector<string> parsedLine;
	const char *str = line.c_str();
	char c = ' ';
	do
	{
		const char *begin = str;

		while (*str != c && *str)
			str++;

		parsedLine.push_back(string(begin, str));
	} while (0 != *str++);


	if (parsedLine.size() == 3) {
		QInt q = QInt(parsedLine[2]);
		if (parsedLine[0] == "2" && parsedLine[1] == "10") {
			result = BinToNumber(BinToBool(parsedLine[2]));
		}
		else if (parsedLine[0] == "10" && parsedLine[1] == "2") {
			result = "Decimal To Binary parsedLine[2]";
		}
		else if (parsedLine[0] == "2" && parsedLine[1] == "16") {
			result = "Bin to Hex";
		}
		else if (parsedLine[0] == "16" && parsedLine[1] == "2") {
			result = BinToNumber(HexToBin(parsedLine[2]));
		}
		else if (parsedLine[0] == "2" && parsedLine[1] == "~") {
			result = BoolToBin((~q).ToBinary);
		}
		else if (parsedLine[0] == "10" && parsedLine[1] == "~") {
			result = BoolToBin((~q).ToBinary);
		}
		else if (parsedLine[0] == "16" && parsedLine[1] == "~") {
			result = BoolToBin((~q).ToBinary);
		}
		else if (parsedLine[0] == "2" && parsedLine[1] == "rol") {
			result = "rol of binary";
		}
		else if (parsedLine[0] == "2" && parsedLine[1] == "ror") {
			result = "ror of binary";
		}


	}

	//operator
	else if (parsedLine.size() == 4) {
		QInt q1 = QInt(parsedLine[1]);
		QInt q2 = QInt(parsedLine[3]);


		if (parsedLine[0] == "2") {
			if (parsedLine[2] == "+") {
				result = BoolToBin((q1+q2).ToBinary());
			}
			else if (parsedLine[2] == "-") {
				result = BoolToBin((q1-q2).ToBinary());
			}
			else if (parsedLine[2] == "*") {
				result = BoolToBin((q1*q2).ToBinary());
			}
			else if (parsedLine[2] == "/") {
				result = BoolToBin((q1/q2).ToBinary());
			}
			else if (parsedLine[2] == "&") {
				result = BoolToBin((q1&q2).ToBinary());
			}
			else if (parsedLine[2] == "|") {
				result = BoolToBin((q1|q2).ToBinary());
			}
			else if (parsedLine[2] == "^") {
				result = BoolToBin((q1^q2).ToBinary());
			}
			else if (parsedLine[2] == "<<") {
				result = "binary << shift amount";
			}
			else if (parsedLine[2] == ">>") {
				result = "binary >> shift amount";
			}

		}
		else if (parsedLine[0] == "10") {
			if (parsedLine[2] == "+") {
				result = BinToNumber((q1+q2).ToBinary());
			}
			else if (parsedLine[2] == "-") {
				result = BinToNumber((q1 - q2).ToBinary());
			}
			else if (parsedLine[2] == "*") {
				result = BinToNumber((q1 * q2).ToBinary());
			}
			else if (parsedLine[2] == "/") {
				result = BinToNumber((q1 / q2).ToBinary());
			}
			else if (parsedLine[2] == "&") {
				result = BinToNumber((q1 & q2).ToBinary());
			}
			else if (parsedLine[2] == "|") {
				result = BinToNumber((q1 | q2).ToBinary());
			}
			else if (parsedLine[2] == "^") {
				result = BinToNumber((q1 ^ q2).ToBinary());
			}
			else if (parsedLine[2] == "<<") {
				result = "binary << shift amount";
			}
			else if (parsedLine[2] == ">>") {
				result = "binary >> shift amount";
			}

		}
		else if (parsedLine[0] == "16") {
			if (parsedLine[2] == "+") {
				result = BinToHex((q1 + q2).ToBinary());
			}
			else if (parsedLine[2] == "-") {
				result = BinToHex((q1 - q2).ToBinary());
			}
			else if (parsedLine[2] == "*") {
				result = BinToHex((q1 * q2).ToBinary());
			}
			else if (parsedLine[2] == "/") {
				result = BinToHex((q1 / q2).ToBinary());
			}
			else if (parsedLine[2] == "&") {
				result = BinToHex((q1 & q2).ToBinary());
			}
			else if (parsedLine[2] == "|") {
				result = BinToHex((q1 | q2).ToBinary());
			}
			else if (parsedLine[2] == "^") {
				result = BinToHex((q1 ^ q2).ToBinary());
			}
			else if (parsedLine[2] == "<<") {
				//result = BinToHex((q1 << q2).ToBinary());
			}
			else if (parsedLine[2] == ">>") {
				//result = BinToHex((q1 >> q2).ToBinary());
			}

		}
	}
	return result;
}
string BinToHex(bool *a)
{
	int k = 0;
	bool *b = new bool[4];
	string result = "";
	for (int i = 0; i < 128; i++)
	{
		if (k != 3)
		{
			b[k] = a[i];
		}
		else
		{
			b[k] = a[i];
			k = 0;
			string l = BoolToBin(b);
			if (l == "0001")result.push_back('1');
			if (l == "0010")result.push_back('2');
			if (l == "0011")result.push_back('3');
			if (l == "0100")result.push_back('4');
			if (l == "0101")result.push_back('5');
			if (l == "0110")result.push_back('6');
			if (l == "0111")result.push_back('7');
			if (l == "1000")result.push_back('8');
			if (l == "1001")result.push_back('9');
			if (l == "1010")result.push_back('A');
			if (l == "1011")result.push_back('B');
			if (l == "1100")result.push_back('C');
			if (l == "1101")result.push_back('D');
			if (l == "1110")result.push_back('E');
			if (l == "1111")result.push_back('F');

		}
	}
	return result;
}