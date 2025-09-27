#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s;

    public:

        //! TC is O(1)
        void enqueue(int x) {
            s.push(x);
        }

        //! TC is O(n)
        int dequeue() {

            //if the stack is empty
            if(s.empty())
                return -1;

            //pop the top element
            int x = s.top();
            s.pop();

            //if stack has only one element then return it
            if(s.empty())
                return x;

            //recursive call
            int item = dequeue();

            //push the popped element back
            s.push(x);

            return item;
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