#include <iostream>
using namespace std;

void permutation(string str, string ans) // Time complexity is O (n!)
{
    int n = str.length();
    if (n == 0)
    {
        cout << ans << endl;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        char ch = str[i];
        string nextstr = str.substr(0, i) + str.substr(i + 1, n - 1 - i);
        permutation(nextstr, ans + ch);
    }
}

int main()
{
    string str = "abc";
    string ans = "";
    permutation(str, ans);
    return 0;
}