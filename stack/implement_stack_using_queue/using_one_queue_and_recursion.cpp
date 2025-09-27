#include<bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

class Stack{
    queue<int> q;

    public:
        void push(int x) {
            int n = q.size();

            q.push(x);

            for(int i =0; i<n; i++) {
                q.push(q.front());

                q.pop();
            }
        }

        void pop() {
            if(q.empty())
                return;

            q.pop();
        }

        int top() {
            if(q.empty())
                return -1;

            return q.front();
        }

        int size() {
            return q.size();
        }

        bool empty() {
            return q.empty();
        }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Size: " << st.size() << endl;

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << "\nSize: " << st.size();
}