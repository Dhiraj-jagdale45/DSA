// WAF to find the exponent value of number in O( long n ) Time complexity
//e.g. 3^2,5^3,4^6 etc.. in general X^n
#include <iostream>
using namespace std;

int fast_exponential(int x ,int n)
{
    int ans = 1;
    while( n > 0)
    {
        int last_digit = n & 1;
        if(last_digit)
        {
            ans *= x;
        }
        x *= x;
        n = n >> 1;
    }
    return ans;
}

int main()
{
    int x = 5;
    int n = 3;
    cout<<fast_exponential(x, n);
    return 0;
}