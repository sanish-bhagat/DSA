#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//TC is O(N)
//SC is O(N)

queue<int> rev(queue<int> &q) {

    stack<int> s;

    while(!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }

    return q;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // while(!q.empty()) {
    //     cout << q.front() << " ";
    //     q.pop();
    // }
    // cout << endl;

    queue<int> ans = rev(q);

    while(!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
}
