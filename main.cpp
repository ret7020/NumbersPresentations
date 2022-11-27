#include <iostream>
#include <string>

typedef long long ll;
using namespace std;

int dec2bin(int num)
{
    int bin = 0, k = 1;
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
    bool DEBUG = true;
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
        ll shift_size = bin_repr.length() - 8 + 1;
        cout << "Shift number for " << shift_size;
        if (shift_size == 0){ // No shift
            res += bin_repr;
        }
        cout << "Direct code: " << res;
    }else{

    }
}