#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int sum = 0;
    while(n > 0){
        int last_digit = n % 10;
        sum += last_digit; //extracting the last digit
        cout << last_digit << endl; //printing the last digit
        n /= 10; //removing the last digit
    }

    cout << "sum of digits: " << sum << endl;
}