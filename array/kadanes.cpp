// //print the maximum Of sum of elelments in subarray using kadanes algorithm T.C-=O(n)
#include <iostream>
#include <climits>
using namespace std;

int kadanes_algorithm(int *arr, int n)
{
    int max_num = INT_MIN;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        max_num = max(max_num, curr_sum);
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return max_num;
}
int main()
{
    int arr[6] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);
    cout << "Max sum of subarray is: " << kadanes_algorithm(arr, n);
    return 0;
}
