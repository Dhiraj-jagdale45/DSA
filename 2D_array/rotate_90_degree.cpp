//Given:- m==n;
#include <iostream>
using namespace std;

void rotate_90(int mat[][3], int n)
{
    // Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    // Reverse each row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(mat[i][j], mat[i][n - 1 - j]);
        }
    }
}

void print_Array(int mat[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << "'";
        }
        cout << endl;
    }
}
int main()
{
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Original matrix: " << endl;
    print_Array(mat, 3);
    rotate_90(mat, 3);
    cout << "matrix after 90 rotation: " << endl;
    print_Array(mat, 3);
    return 0;
}