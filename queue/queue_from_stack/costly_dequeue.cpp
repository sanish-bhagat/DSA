#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;

    public:

        //! TC is O(1)
        void enqueue(int x) {
            s1.push(x);
        }

        //! TC is O(n)
        int dequeue() {
            if(s1.empty() && s2.empty())
                return -1;

            if(s2.empty()) {
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            int x = s2.top();
            s2.pop();
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