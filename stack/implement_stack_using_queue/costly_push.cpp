#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q1, q2;

    public:

        //! TC is O(n)
        void push(int x) {
            q2.push(x);

            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }

            swap(q1, q2);
        }

        //! TC is O(1)
        void pop() {
            if(q1.empty())
                return ;
            q1.pop();
        }

        int top() {
            if(q1.empty())
                return -1;

            return q1.front();
        }

        int size() {
            return q1.size();
        }

        bool isempty() {
            return q1.size() == 0;
        }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Size: " << st.size() << endl;

    while(!st.isempty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << "\nSize: " << st.size() << endl;
}