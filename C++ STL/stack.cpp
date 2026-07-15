#include <bits/stdc++.h>
using namespace std;

void explainStack(){
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(5);
    st.push(7);
    cout << st.top();
    st.pop(); //doesnt return
    cout << st.size();
    cout << st.empty();

    //size and swap functions
}

int main(){
    explainStack();
}