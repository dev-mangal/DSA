#include <bits/stdc++.h>
using namespace std;

void explainQueue(){
    queue<int> q;
    q.push(2); //{2}
    q.push(3); //{2,3}
    q.emplace(4); //{2,3,4}

    q.back() += 5; //q.back means 4 i.e the last value added
    q.front() -= 1; //q.front means the first value added

    //{1,3,9}
    cout << q.back() << q.front() << endl;
    q.pop(); //pops 1 => {3,9}
    cout << q.front() << endl; //3
}

int main(){
    explainQueue();
}