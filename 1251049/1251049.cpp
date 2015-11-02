#include "1251049.h"

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
		if (a[i]==1)
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
			result = result+pow(2,31-i);
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
		for (int i = result.length()-1; i >= 0; i--)
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
			result[i] = ((result[i] - 48) * 2) % 10 + tmp1 +48;
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
			num2.push_back(num2[num2.length()-1]);
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
		result[i] = ((num1[i] + num2[i]-48-48) % 10) +tmp+48;
		if (result[i] == 58) 
			result[i] -= 10;
		if (num1[i] + num2[i]+tmp -48-48>9)
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
	if (diff > 0)
	{
		for (int i = 0; i < diff; i++)
		{
			bin2.push_back(bin2[bin2.length() - 1]);
		}
		for (int j = bin2.length() - 1 - diff; j > 0; j--)
		{
			bin2[j] = bin2[j - 1];
		}
		for (int i = 0; i < diff; i++)
		{
			bin2[i] = '0';
		}
	}
	else if (diff<0)
	{
		diff *= -1;
		for (int i = 0; i < diff; i++)
		{
			bin1.push_back(bin1[bin1.length() - 1]);
		}
		for (int j = bin1.length() - 1 - diff; j > 0; j--)
		{
			bin1[j] = bin1[j - 1];
		}
		for (int i = 0; i < diff; i++)
		{
			bin1[i] = '0';
		}
	}
	string result;
	for (int i = 0; i < bin1.length(); i++)
	{
		result.push_back('0');
	}
	int tmp = 0;
	for (int i = bin1.length() - 1; i >= 0; i--)
	{
		result[i] = (((bin1[i] + bin2[i] - 48 - 48) % 2) + tmp) % 2 + 48;
		if ((bin1[i] + bin2[i] + tmp - 48 - 48)>1)
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