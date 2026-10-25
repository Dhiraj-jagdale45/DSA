// print the whether given number is power of two or not
#include <iostream>
using namespace std;

int is_pow_2(int num)
{
    if (!(num & (num - 1)))
    {
        return 1;
    }
    return 0;
}
int main()
{
    int num = 6;
    cout << is_pow_2(num);
    return 0;
}