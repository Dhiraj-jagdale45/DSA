// print alll the ways to reach from (0,0) to (m-1,n-1) in a m x n Grid
//Allowed moves are :- Right,Down
#include <iostream>
using namespace std;

int possible_ways(int m, int n, int row, int col, string ans)// Time complexity is O(2^(m+n))
{
    int count_right = 0, count_down = 0;
    if (m <= row || n <= col)
    {
        return 0;
    }
    if (m - 1 == row && n - 1 == col)
    {
        cout << ans << endl;
        return 1;
    }

    //Right 
    count_right += possible_ways(m, n, row, col + 1, ans + "R");

    //Down
    count_down += possible_ways(m, n, row + 1, col, ans + "D");

    return(count_right + count_down);
}

int main()
{
    int m = 2;
    int n = 2;
    string ans;
    int ways = possible_ways(m, n, 0, 0, ans);
    cout << ways;
    return 0;
}