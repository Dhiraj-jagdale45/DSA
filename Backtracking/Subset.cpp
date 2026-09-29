// Find and print all subsets of given string
#include <iostream>
using namespace std;

void print_subset(string str, string subset_str) // time coplexity is O(2^n)
{
    if (str.length() == 0)
    {
        cout << subset_str << "\n";
        return;
    }
    char ch = str[0];
    // For choise yes
    print_subset(str.substr(1, str.length() - 1), subset_str + ch);
    // For no choise
    print_subset(str.substr(1, str.length() - 1), subset_str);
}

int main()
{
    string str = "abcd";
    string subset_str = "";
    print_subset(str, subset_str);
    return 0;
}