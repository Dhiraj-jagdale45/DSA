// Find Xor - beauty of array
// pproblem no. 2527 on leetcode
#include <iostream>
#include <vector>
using namespace std;

int Xor_beauty(vector<int> arr)
{
    int size = arr.size();
    int x = 0;
    int Xor_val;
    int ans = ((arr[0] | arr[0])) & arr[0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if(i == 0 && j == 0 && k == 0)
                    continue;
                Xor_val = ((arr[i] | arr[j])) & arr[k];
                ans = ans ^ Xor_val;
                x++;
            }
        }
    }
    cout<<x<<endl;
    return ans;
}

int main()
{
    vector<int> vec = {15, 45, 20};
    cout << Xor_beauty(vec);
    return 0;
}