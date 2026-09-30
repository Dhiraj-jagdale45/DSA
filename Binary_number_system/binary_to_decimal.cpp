#include<iostream>
#include<cmath> //cmath library has the pow(base, exponent);
using namespace std;

int bin_to_dec(int n) {
    int decimal = 0;
    int power = 0;
    while(n > 0) {
        int digit = n % 10;
        if(digit == 0) {
            n /= 10;
        }else{
            decimal += pow(2, power);
            n /= 10;
        }
        power++;
    }
    return decimal;

}

int main() {
    int n;
    cout << "Enter the binary digit: ";
    cin >> n;
    cout << "Decimal of given binary is: " << bin_to_dec(n);
    return 0;
}
