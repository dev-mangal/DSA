#include <bits/stdc++.h>
using namespace std;

//in parameter for comp, use the data type of the array, since the elements are being compared to each other
bool comp(pair<int, int> p1, pair<int,int> p2){
    if(p1.second < p2.second) return true;
    else if(p1.second > p2.second) return false;

    if(p1.first > p2.first) return true;

    return false;
}

void extra(){
    //sort(a, a+n) where n = size of array
    //sort(v.begin(), v.end())
    //sort(a + x, a + y) for a specific range within array to be sorted
    //sort(a, a+n, greater<int>) for desc sort
    pair<int, int> a[] = {{1,2}, {2,1}, {4,1}};

    //sort acc to second element, if equal then acc to first element in desc
    sort(a, a + 3, comp); //comp is a user defined comparator, boolean function

    for(auto it : a){
        cout << it.first << " " << it.second << endl;
    }
}

int main(){
    extra();
    int num = 7;
    int cnt = __builtin_popcount(num); //counts the number of set bits (1)
    cout << cnt << endl;

    long long num2 = 180382104891334;
    cnt = __builtin_popcountll(num2);
    cout << cnt << endl;

    //need to sort the string first to get all the permutations according to dictionary sort
    string s = "213";
    sort(s.begin(), s.end());
    do{
        cout << s << endl;
    }while(next_permutation(s.begin(), s.end()));

    //int maxi = *max_element(a, a+n) same for min
}