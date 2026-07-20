#include <bits/stdc++.h>
#include <climits>
using namespace std;

int reverse(int x) {
        //last digit ke liye we get the factor of 10
        //baaki digits ke liye we get remainder when we divide by 10
        //and then in the loop multiply by the power of 10
        //when ending with zero if condition to check if divisible by 10 then we remove all zeros and get the digits
        int n = x;
        int last_digit;
        int reverse_int = 0;

        while(n != 0){
            last_digit = n%10;
            //check limits, equation came from reverse_int*10 + last_digit > INT_MAX and reverse_int*10 + last_digit < INT_MIN
            // if(reverse_int > (INT_MAX - last_digit) / 10 || reverse_int < (INT_MIN + last_digit) / 10) return 0;
            // this also gives error since the check itself can overflow, so we need to check the reverse_int before multiplying by 10
            if (reverse_int > INT_MAX / 10 || (reverse_int == INT_MAX / 10 && last_digit > 7)) return 0;

            if (reverse_int < INT_MIN / 10 || (reverse_int == INT_MIN / 10 && last_digit < -8)) return 0;
            
            reverse_int = reverse_int * 10 + last_digit;
            n = n/10;
        }
        return reverse_int;
}

int main(){
    int result = reverse(1534236469);
    cout << result << endl;
}