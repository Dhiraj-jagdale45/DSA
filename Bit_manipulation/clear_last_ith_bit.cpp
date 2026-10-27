// WAF to clear last ith bit of a number
#include <iostream>
using namespace std;

int clear_bit(int num, int ith_bit)
{
    return ((num >> 2) << 2);
}

int main()
{
    int num = 15;
    int ith_bit = 2;
    cout << clear_bit(num, ith_bit);
    return 0;
}