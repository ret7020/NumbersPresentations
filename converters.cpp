#include <iostream>
#include <string.h>
#include "utils.h"

string extra_code_gen(string s1, string form_odin, int size)
{
	string result="";
	int carry = 0;
	for (int i = size-1; i>=0;i--)
	{
		int bit1 = s1.at(i) - '0';
		int bit2 = form_odin.at(i) - '0';
		char sum = (bit1 ^ bit2 ^ carry) + '0';
		result = sum + result;
		carry = (bit1 & carry) | (bit2 & carry) | (bit1 & bit2);
	}
	if (carry) {
		result = "1" + result;
	}
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
