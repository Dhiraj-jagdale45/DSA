#include <iostream>
#include <vector>
using namespace std;

void print_board(vector<vector<char>> board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}

bool is_safe(vector<vector<char>> board, int row, int col)
{
    int n = board.size();
    //Check in Horizontal
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }

    //check in Vertically
    for(int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    //Check in left Diagonal
    for(int i = row, j = col; i >= 0 && j >=0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    //Check in Right Diagonal
    for(int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

bool N_Queens(vector<vector<char>> &board, int row)
{
    int n = board.size();

    // Base case
    if (row == n)
    {
        print_board(board);
        return true;   // STOP after first solution
    }

    for (int i = 0; i < n; i++)
    {
        if (is_safe(board, row, i))
        {
            board[row][i] = 'Q';

            // If solution found, stop recursion
            if (N_Queens(board, row + 1))
                return true;

            board[row][i] = '-'; // Backtrack
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> board;
    int n = 8;
    for (int i = 0; i < n; i++)
    {
        vector<char> row;
        for (int j = 0; j < n; j++)
        {
            row.push_back('-');
        }
        board.push_back(row);
    }
    N_Queens(board, 0);
    return 0;
}