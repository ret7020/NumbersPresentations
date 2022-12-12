#include <iostream>
#include <string>
#include "utils.h"
#include "converters.h"
using namespace std;

int main()
{
    int number, size;
    string binary = "";
    int number_processing_mode = 0;
    cout << generate_colored("Input number: ", 1);
    cin >> number;
    cout << generate_colored("Saved size: ", 1);
    cin >> size;
    if (number < 0) binary = to_binary_string(-number);
    else binary = to_binary_string(number);
    string binary_code_format = "";
    string extra_code_format = "";
    int length = binary.size();

    cout << "**** RESULT ****\n";
    cout << generate_colored("Binary form: ", 2) << binary << endl;
    binary_code_format = process_binary_number(binary, size, length, number);
    cout << generate_colored("Direct code: ", 2) << binary_code_format << endl;

    if (number < 0)
    {
        if (size - length < 0)
            number_processing_mode = 0;
        else
        {
            number_processing_mode = 1;
            extra_code_format += "1";
        }

        for (int i = number_processing_mode; i < size; ++i)
        {
            if (binary_code_format[i] == '0')
                extra_code_format += '1';
            else
                extra_code_format += '0';
        }
        cout << generate_colored("Reverse code: ", 2) << extra_code_format << endl;
        string odin = process_binary_number( "1", size, 1, 1);
		string extra_code_final = extra_code_gen(extra_code_format, odin, size);
		int length2 = extra_code_final.size();
	    if (size - length2 < 0) extra_code_final = extra_code_final.erase(0, length2 - size);
		cout << generate_colored("Extra code: ", 2) << extra_code_final << endl;

    }
}
