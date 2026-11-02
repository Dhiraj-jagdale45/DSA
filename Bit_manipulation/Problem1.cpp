// clear the all the bits ranging from ith position to jth position 
// e.g. num = 31; i = 1, j = 3, o/p:- 17+
#include <iostream>
using namespace std;

int new_number(int num, int j, int i)
{
    while (i <= j)
    {
        num = num & ~((1 << i));
        i++;
    }
    return num;
}

int main()
{
    int num = 15;
    int j = 3, i = 1;
    cout << new_number(num, j, i);
    return 0;
}