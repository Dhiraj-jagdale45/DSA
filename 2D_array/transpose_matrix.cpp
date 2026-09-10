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

void transpose_matrix(int (*mat)[3], int m, int n)
{
    int (*tra_mat)[3];
    tra_mat = new int[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tra_mat[i][j] = mat[j][i];
        }
    }
    print_Array(tra_mat, m, n);
}

int main()
{
    int mat[3][3] = {{1, 2, 8}, {3, 4, 7}, {5, 6, 9}};
    int n = sizeof(mat[0]) / sizeof(int);
    int m = sizeof(mat) / sizeof(int) / n;
    transpose_matrix(mat, m, n);
    return 0;
}