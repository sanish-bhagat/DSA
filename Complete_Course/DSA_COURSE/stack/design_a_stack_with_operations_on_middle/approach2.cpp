#include<bits/stdc++.h>
using namespace std;

//! deleting of the middle element can be done in O(1) time

class myStack{
    stack<int> st;
    deque<int> dq;

    public:
        void push(int data) {
            dq.push_back(data);
            if(dq.size() > st.size() + 1) {
                int temp = dq.front();
                dq.pop_front();
                st.push(temp);
            }
        }

        void pop() {
            dq.pop_back();
            if(st.size() > dq.size()) {
                int temp = st.top();
                st.pop();
                dq.push_front(temp);
            }
        }

        int getMiddle() {
            return dq.front();
        }

        void deleteMiddle() {
            dq.pop_front();
            if(st.size() > dq.size()) {
                int temp = st.top();
                st.pop();
                dq.push_front(temp);
            }
        }

        int top() {
            return dq.back();
        }
};

int main() {
    myStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << "Middle element is: " << st.getMiddle() << endl;
    cout << "Top element is: " << st.top() << endl;
    st.pop();
    cout << "Middle element is: " << st.getMiddle() << endl;
    cout << "Top element is: " << st.top() << endl;
    st.deleteMiddle();
    cout << "Middle element is: " << st.getMiddle() << endl;
    cout << "Top element is: " << st.top() << endl;
}