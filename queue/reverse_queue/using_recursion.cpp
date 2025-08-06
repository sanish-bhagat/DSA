#include<bits/stdc++.h>
using namespace std;

void print(queue<int> q) {
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

void reverseRec(queue<int> &q) {
    //base case
    if(q.empty())
        return;

    int data = q.front();
    q.pop();

    //recursive call
    reverseRec(q);

    //push the popped element
    q.push(data);
}

//! TC is O(n)
//! SC is O(n)

queue<int> reverseQueue(queue<int> q) {
    reverseRec(q);
    return q;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    print(q) ;
    cout << endl;

    queue<int> res = reverseQueue(q);
    print(res);
}