// single number problem on leetcode
// problem no. 136 on leetcode
#include <iostream>
#include <algorithm>
using namespace std;

void single_num(int *arr, int n)
{
    sort(arr, arr+n);
    for (int i = 0; i < n; i++)
    {
        if(i != n - 1)
        {
            if (arr[i] == arr[i + 1])
            {
                i++;
                continue;
            }
        }
        cout << arr[i];
    }
}

int main()
{
    int arr[] = {4, 1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(int);
    single_num(arr, n);
    return 0;
}