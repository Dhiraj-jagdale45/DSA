#include <iostream>
using namespace std;

int main()
{
    int n, ith_bit;
    cout << "Enter the number : " << endl;
    cin >> n;
    cout << "Enter the ith bit position : " << endl;
    cin >> ith_bit;
    cout << ith_bit << " bit of " << n << " is " << ((n >> ith_bit) & 1);
    return 0;
}