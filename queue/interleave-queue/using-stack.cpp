#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//TC is O(N);
//SC is O(N)

void interleaveQueue(queue<int> &q) {
    stack<int> s;

    int halfSize = q.size() / 2;

    //first half queue -> stack
    for(int i=0; i<halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    //stack -> queue
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    //first half q.pop() and q.push()
    for(int i=0; i<halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    //first half of q -> stack
    for(int i=0; i<halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()) {
        q.push(s.top());
        s.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);

    interleaveQueue(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}