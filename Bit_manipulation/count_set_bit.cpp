//WAF to written number set value in a number
#include <iostream>
#include <vector>
using namespace std;

int total_set_bit(int num)
{
    int count = 0;
    while (num > 0)
    {
        int last_digit = num & 1;
        count += last_digit;
        num = num >> 1;
    }
    return count;
}

int main()
{
    int num = 10;
    cout << total_set_bit(num);
    return 0;
}