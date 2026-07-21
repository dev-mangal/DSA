#include <bits/stdc++.h>
using namespace std;

// if number equal to sum of its digits raised to the power of number of digits then it is called armstrong number
bool isArmstrong(int num) {
    //count the number of digits
    //then take each digit in loop and raise to the count
    string str = to_string(num);
    int temp = num;
    int count = str.length();
    if(num < 0) count -= 1; //usually negative numbers not included but if u want to then this condition used
    int result = 0;
    for(int i = 0; i < count; i++){
        result += pow(temp%10, count);
        temp = temp/10;
    }
    return result == num;
}

int main(){
    bool result = isArmstrong(-123);
    if(result == true) cout << "true" << endl;
    else cout << "false" << endl;
}