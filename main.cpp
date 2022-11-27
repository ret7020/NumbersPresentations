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
    ll number, base_size = 8;
    cout << "Enter number: ";
    cin >> number;
    cout << "Enter size: ";
    cin >> base_size;
    cout << "Storing " << number << "in size " << base_size << "\n";
    ll res_bin =  dec2bin(number);
}