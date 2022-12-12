#include <iostream>
#include <string.h>
#include "utils.h"

string extra_code_gen(string s1, string base_bin, int size)
{
	string result = "";
	int payload = 0;
	char sum;
	for (int i = (size - 1); i >= 0; --i)
	{
		int bitLeft = s1.at(i) - '0';
		int bitRight = base_bin.at(i) - '0';
		sum = (bitLeft ^ bitRight ^ payload) + '0';
		result = sum + result;
		payload = (bitLeft & payload) | (bitRight & payload) | (bitLeft & bitRight);
	}
	if (payload) result = "1" + result;
	return result;
}
string process_binary_number(string binary, int size, int length, int number)
{
    string temp_res = "";
    if (size - length > 0)
    {
        if (number >= 0)
            temp_res = string((size - length), '0') + binary;
        else
            temp_res = '1' + string((size - length - 1), '0') + binary;
    }
    else if (size - length < 0)
    {
        cout << generate_colored("Warning! Overflow, some bits deleted", 0) << endl;
        temp_res = binary.erase(0, length - size);
    }
    else if (size - length == 0)
    {
        cout << generate_colored("Warning! Overflow, some bits deleted", 0) << endl;
        temp_res = binary;
    }
    return temp_res;
}

string to_binary_string(int n)
{
    string result = "";
    while (n > 0)
    {
        result += '0' + n % 2;
        n /= 2;
    }
    return string(result.crbegin(), result.crend());
}
