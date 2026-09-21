#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Trapped_Water(int *arr, int n)
{
    if (n <= 2)
        return 0;

    vector<int> left_max(n);
    vector<int> right_max(n);

    int water_trapped = 0;

    left_max[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        left_max[i] = max(left_max[i - 1], arr[i]);
    }

    right_max[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        right_max[i] = max(right_max[i + 1], arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int current_water =
            min(left_max[i], right_max[i]) - arr[i];

        if (current_water > 0)
            water_trapped += current_water;
    }

    return water_trapped;
}

int main()
{
    int arr[] = {0, 4, 0, 5, 4, 3, 2, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Trapped Water is: " << Trapped_Water(arr, n);

    return 0;
}