// Time complexity is O(n)
#include <iostream>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int grid_ways(int m, int n)// here we use permutation formula
{
    int a = factorial(m - 1 + n - 1);
    int b = factorial(m - 1);
    int c = factorial(n - 1);
    return (a / (b*c));
}

int main()
{
    int m = 4;
    int n = 4;
    cout << grid_ways(m, n);
    return 0;
}