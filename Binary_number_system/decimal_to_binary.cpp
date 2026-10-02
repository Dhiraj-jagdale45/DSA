#include<iostream>
using namespace std;

void decimal_to_binary(int n)
{
    int result=0,digit,i=1;
    while(n>0)
    {
        digit=n%2;
        result+=digit*i;
        // cout << result << endl;
        n/=2;
        i*=10;
    }
    cout<<result;
}

int main()
{
    int dec_num;
    cout<<"Enter the Decimal number :";
    cin>>dec_num;
    cout<<"Decimal number is :";
    decimal_to_binary(dec_num);
    return 0;
}
