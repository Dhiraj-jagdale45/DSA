// //Print all the subarray in given array
// #include <iostream>
// using namespace std;

// void print_all_subarray(int *arr, int n)
// {
//     for(int k=0;k<n;k++)
//     {
//         for (int i = k; i < n; i++)
//         {
//             cout << "( ";
//             for (int j = k; j <= i; j++)
//             {
//                 cout << arr[j] << " ";
//             }
//             cout << ")";
//             cout << "    ";
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     int arr[3] = {1, 2, 3};
//     int n = sizeof(arr) / sizeof(int);
//     print_all_subarray(arr, n);
//     return 0;
// }



#include<iostream>
#include<string>
using namespace std;

void printSubarray(int arr[], int n) {
    string str = "";
    for(int i = 0; i < n; i++) {
        str += to_string(arr[i]);
        cout << str << ", ";
        for(int j = i + 1; j < n; j++) {
            str += to_string(arr[j]);
            cout << str << ", ";
        }
        cout << endl;
        str = "";
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    printSubarray(arr, n);
    return 0;
}