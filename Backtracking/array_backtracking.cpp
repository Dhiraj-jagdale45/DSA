#include <iostream>
using namespace std;

void print_Array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void back_tracking_array(int arr[], int n, int i)
{
    if(i == n)
    {
        print_Array(arr, n);
        return;
    }
    arr[i] = i + 1;
    back_tracking_array(arr, n, i + 1); // backtracking call
    arr[i] = arr[i] - 2;
}

int main()
{
    int arr[5] = {0};
    int n = 5;
    back_tracking_array(arr, n, 0);
    print_Array(arr, n);
    return 0;
}