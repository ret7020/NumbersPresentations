#include <iostream>
#include <string>

typedef long long ll;
using namespace std;

ll dec2bin(ll num)
{
    ll bin = 0, k = 1;
    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }
    return bin;
}

int main(){
    // CONFIG PART
    bool DEBUG = false;
    int COLORS_SYSTEM = 0;  // 0 - BASH(LINUX THE BEST); 1 - CMD(WINDOWS); 2 - DISABLED
    //
    ll number, base_size = 8;
    cout << "Enter number: ";
    cin >> number;
    cout << "Enter size: ";
    cin >> base_size;
    if(DEBUG) cout << "Storing " << number << "in size " << base_size << "\n";
    ll res_bin =  dec2bin(number);
    if (DEBUG) cout << "Binary repr: " << res_bin << "\n";
    string res = "";
    if (number > 0){
        if (DEBUG) cout << "Possitive number";
        res += "0";
        string bin_repr = to_string(res_bin);
        ll shift_size = bin_repr.length() - base_size + 1;
        if (DEBUG) cout << "Shift number for " << shift_size << "\n";
        if (shift_size == 0) // No shift
            res += bin_repr;
        else if (shift_size < 0) // Inject zeros
            res += string(abs(shift_size), '0') + bin_repr;
        else if (shift_size > 0){
            cout << shift_size + 1;
            res += bin_repr.substr(shift_size);
            cout << "[WARN] OVERFLOW; SOME NUMBERS SHIFTED\n";
        }
        cout << "Direct code: " << res;
    }else{

    }
}