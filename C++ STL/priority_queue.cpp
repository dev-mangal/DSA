#include <bits/stdc++.h>
using namespace std;

void explainPQ(){
    //max heap
    priority_queue <int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(8);
    pq.push(5); //{8 5 4 2}
    pq.emplace(10);
    pq.pop();
    cout << pq.top() << endl; //8

    //min heap
    priority_queue<int, vector<int>, greater<int>> pq_min;
    pq_min.push(5);
    pq_min.push(2);
    pq_min.push(8);
    pq_min.push(1); //{1 2 5 8}
    cout << pq_min.top() << endl; //1
}

int main(){
    explainPQ();
}