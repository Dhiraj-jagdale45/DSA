//given:-no. of rows == no. of column
#include <iostream>
using namespace std;

int diagonal_sum(int mat[][3], int m, int n)
{
    int row_primary = 0, row_secondary = 0, column_primary = 0, column_secondary = n - 1;
    int count = 0, sum_of_diagonal = 0;
    while (count < n)
    {
        if (row_primary != row_secondary || column_primary != column_secondary)
        {
            sum_of_diagonal += (mat[row_primary][column_primary] + mat[row_secondary][column_secondary]);
        }
        else
        {
            sum_of_diagonal += (mat[row_primary][column_primary]);
        }
        count++;
        row_primary++;
        column_primary++;
        row_secondary++;
        column_secondary--;
    }
    return sum_of_diagonal;
}

int main()
{
    int mat[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = sizeof(mat[0]) / sizeof(int);
    int m = sizeof(mat) / sizeof(int) / n;
    cout << diagonal_sum(mat, m, n);
    return 0;
}