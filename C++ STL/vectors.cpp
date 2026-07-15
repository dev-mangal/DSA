#include <bits/stdc++.h>
using namespace std;

void explainVector(){
    vector<int> v; // {}
    v.push_back(1);// {1}
    v.emplace_back(2);// {1,2}

    //emplace back is faster than push back, both do the same thing of adding elements
    //size of vector can be changed even if it is defined with a given size

    vector<pair<int, int>> vec(5); //{{0,0},{0,0},{0,0},{0,0},{0,0}}
    vec.push_back({1,2}); //{{0,0},{0,0},{0,0},{0,0},{0,0},{1,2}}
    vec.emplace_back(1,2); //syntax difference, automatically assumes 1,2 is a pair

    vector<int> v2(5,100); //{100,100,100,100,100}
    v2.emplace_back(6);
    v2.emplace_back(3);
    vector<int> v3(v2); //copies the contents of v2

    vector<int>::iterator it = v2.begin(); //points to beginning of the vector i.e first element
    cout << *it << endl;
    it += 5;
    cout << *it << endl;

    vector<int>::iterator it_end = v2.end(); //points to the memory address just after the last element of the vector
    it_end--;
    cout << *it_end;

    cout << v2.back() << endl; //also prints the last element of the vector
    cout << '\n';

    //iterator loop to print through the vector, can use normal indexing loop too
    for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++){ //auto it = v2.begin()
        cout << *it << ',';
    }
    cout << '\n';
    //for(auto it : v) //this is not an iterator, just goes thru the vector

    //deletion
    v2.erase(v2.begin(), v2.begin() + 4); //give the range using addresses, {100,6,3} is left
    for(auto it : v2){
        cout << it << ',';
    }
    cout << '\n';

    //insertion
    v2.insert(v2.begin() + 2, 4, 100); //the number of elements is optional
    for(auto it : v2){
        cout << it << ',';
    }
    cout << '\n';
    vector<int> copy(4, 50); //{50,50,50,50}
    v2.insert(v2.begin(), copy.begin(), copy.begin() + 2);
    for(auto it : v2){
        cout << it << ',';
    }
    //v.size
    //v.pop_back pops the last element, destroys it and doesnt return anything, use back() to get last element's copy 
    //v.swap(v1) swaps the names of the vectors
    //v.clear() empties the vector and v.empty() checks whether the vector is empty
}

int main(){
    explainVector();
}