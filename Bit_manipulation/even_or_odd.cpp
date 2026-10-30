#include <iostream>
using namespace std;

int main()
{
    int n = 11;
    if (!(n & 1))
        cout << "No. is even...";
    else
        cout << "No. is odd...";
    return 0;
}