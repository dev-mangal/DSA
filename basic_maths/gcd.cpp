#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    //Calculate GCD using Euclidean algorithm
    //gcd(a,b) = gcd(b, a%b)
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    cout << "GCD is: " << a << endl;
    return 0;
}