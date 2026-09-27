#include <iostream>
using namespace std;

void print_ans(int sudo[][9])
{
    for (int i = 0; i <= 8; i++)
    {
        for (int j = 0; j <= 8; j++)
        {
            cout << sudo[i][j] << " ";
        }
        cout << endl;
    }
}

bool issafe(int sudo[][9], int row, int col, int digit)
{
    // Horizontal
    for (int i = 0; i <= 8; i++)
    {
        if (sudo[row][i] == digit)
        {
            return false;
        }
    }

    // Vertical
    for (int j = 0; j <= 8; j++)
    {
        if (sudo[j][col] == digit)
        {
            return false;
        }
    }

    // 3 x 3 Grid
    int startrow = (row / 3) * 3;
    int startcolumn = (col / 3) * 3;
    for (int i = startrow; i <= startrow + 2; i++)
    {
        for (int j = startcolumn; j <= startcolumn + 2; j++)
        {
            if (sudo[i][j] == digit)
            {
                return false;
            }
        }
    }

    return true;
}

bool Suduko_solver(int sudo[][9], int row, int col)
{
    int nextrow = row, nextcolumn = col + 1;
    if (nextrow == 9)
    {
        print_ans(sudo);
        return true;
    }
    if (col + 1 == 9)
    {
        nextrow = row + 1;
        nextcolumn = 0;
    }

    if (sudo[row][col] != 0)
    {
        Suduko_solver(sudo, nextrow, nextcolumn);
    }
    else
    {
        for (int dig = 1; dig <= 9; dig++)
        {
            if (issafe(sudo, row, col, dig))
            {
                sudo[row][col] = dig;
                Suduko_solver(sudo, nextrow, nextcolumn);
                sudo[row][col] = 0;
            }
        }
    }
}
int main()
{
    int sudo[9][9] = { 
                        {9, 0, 0, 0, 0, 2, 0, 0, 7}, 
                        {0, 0, 0, 0, 0, 7, 0, 5, 0}, 
                        {0, 0, 0, 0, 6, 0, 0, 1, 3}, 
                        {0, 0, 0, 6, 0, 0, 0, 0, 9},
                        {0, 9, 0, 0, 3, 0, 1, 0, 2},
                        {7, 0, 0, 2, 1, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 4, 0},
                        {2, 0, 0, 0, 0, 0, 8, 0, 1},
                        {0, 0, 0, 0, 5, 0, 0, 0, 0}
                    };
    Suduko_solver(sudo, 0, 0);
    return 0;
}