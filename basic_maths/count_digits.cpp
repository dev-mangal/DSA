#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    int count = 0;
    // while(n > 0){
    //     n = n / 10; //removing the last digit
    //     count++; //counting the number of digits
    // }
    count = log10(n) + 1; //using logarithm to count the number of digits
    cout << "Number of digits: " << count << endl;
}