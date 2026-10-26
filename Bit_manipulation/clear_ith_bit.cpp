#include <iostream>
using namespace std;

int clear_ith_bit(int n, int ith)
{
    return (n & (~(1 << ith)));
}
int main()
{
    int n = 7;
    int position = 1;
    cout << clear_ith_bit(n, position);
    return 0;
}