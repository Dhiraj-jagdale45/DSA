#include <iostream>
using namespace std;

void print_Array(int mat[][3], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << ",";
        }
        cout << endl;
    }
}

void converter_into_2D(int arr[], int m, int n)
{
    int (*mat)[3] = new int[m][3];

    int index = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = arr[index];
            index++;
        }
    }

    print_Array(mat, m, n);

    delete[] mat;
}

int main()
{
    int arr[3] = {1, 2, 3};

    converter_into_2D(arr, 1, 3);

    return 0;
}