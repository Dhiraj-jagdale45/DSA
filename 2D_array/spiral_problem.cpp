#include <iostream>
using namespace std;

void spiral_of_matrix(int mat[][1], int m, int n)
{
    int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;
    while (srow <= erow && scol <= ecol)
    {
        // top
        for (int j = scol; j <= ecol; j++)
        {
            cout << mat[srow][j] << "  ";
        }
        // right
        for (int i = srow + 1; i <= erow; i++)
        {
            cout << mat[i][ecol] << "  ";
        }
        // bottom
        for (int j = ecol - 1; j >= scol; j--)
        {
            if(srow==erow)
            {
                break;
            }
            cout << mat[erow][j] << "  ";
        }
        // left
        for (int i = erow - 1; i >= srow + 1; i--)
        {
            if(scol==ecol)
            {
                break;
            }
            cout << mat[i][scol] << "  ";
        }
        srow++;
        scol++;
        ecol--;
        erow--;
    }
    cout << endl;
}

int main()
{
    int mat[3][1] = {{1},
                     {5},
                     {9},
                    };
    int n = sizeof(mat[0]) / sizeof(int);
    int m = sizeof(mat) / sizeof(int) / n;
    spiral_of_matrix(mat, m, n);
    return 0;
}