#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;

    public:

    //! TC is O(n)
        void enqueue(int x) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            s1.push(x);

            while(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }

        //! TC is O(1)
        int dequeue() {
            if(s1.empty())
                return -1;

            int x = s1.top();
            s1.pop();
            return x;
        }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}