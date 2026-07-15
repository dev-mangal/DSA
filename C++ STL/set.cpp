#include <bits/stdc++.h>
using namespace std;

void explainSet(){
    set<int> s;
    s.insert(2); //{2}
    s.insert(1); //{1,2}
    s.insert(4); //{1,2,4}
    s.insert(3); //{1,2,3,4}
    s.insert(2); //nothing happens
    s.insert(5); //{1,2,3,4,5}

    //begin, end, rbegin, rend are pointers only, rend points to the memory before the first i.e smallest element
    auto it = s.find(3); //it now points to 3 inside the set
    cout << *it << endl;

    //{1,2,3,4,5}
    it = s.find(6); //if element is not in set, then it acts like s.end()
    cout << *(--it) << endl;

    s.erase(4); //erases 4 and maintains the sorted order, takes logarithmic time
    s.erase(it); //can also use pointer to refer to the element
    s.insert(5);
    s.insert(4);

    //range [first, last), erases 2 3 4
    auto it1 = s.find(2);
    auto it2 = s.find(5);
    s.erase(it1, it2);
    cout << "elements in set are ";
    for(auto i : s){
        cout << i << " ";
    }
    cout << endl;
    //int cnt = s.count(1); 

    //begin end functions same as vectors

    // //lower bound function
    // int a[] = {1,4,5,6,9,10};
    // //not subtracting index of a gives an error, to get index we have to subtract first element
    // int index = lower_bound(a, a+6, 4) - a; //index = 1
    // cout << index << endl;
    // index = lower_bound(a, a+6, 7) - a; //if element not present, then chooses the immediate next greater value i.e 9, index = 4
    // cout << index << endl;
    // index = lower_bound(a, a+6, 11) - a; //index = 6 since no value greater than 11
    // cout << index << endl;
    // //lower_bound(a.begin(), a.end(), x) - a.begin() for vectors

    // //upper bound function, returns iterator to element greater than req, if found, otherwise same as lower bound
    // int a[] = {1,4,5,6,9,10};
    // int index = upper_bound(a, a+6, 4) - a; //index = 2
    // cout << index << endl;
    // index = upper_bound(a, a+6, 7) - a; //index = 4
    // cout << index << endl;
    // index = upper_bound(a, a+6, 11) - a; //index = 6
    // cout << index << endl;

    //{1,2,3,4,5}
    it = s.lower_bound(5); //same logic as arrays, iterator of element >= 5, or s.end() if 5 DNE
    cout << "lower bound of 5: " << *it << endl;
    it = s.upper_bound(4); //upper bound(5) points to s.end(), so undefined behavior
    cout << "upper bound of 5: " << *it << endl;
}

int main(){
    explainSet();
}