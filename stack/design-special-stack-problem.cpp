#include<bits/stdc++.h>
using namespace std;

//TC is O(1)
//SC is O(1)

class SpecialStack {
    //define the data structure
    stack<int> s;
    int mini = INT_MAX;

    public:

    void push(int data) {
        //for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else {
            if(data < mini) {
                int val = 2 * data - mini;
                s.push(val);
                mini = data;
            }
            else {
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()) {
            return -1;
        }

        int curr = s.top();
        s.pop();

        if(curr > mini) {
            return curr;
        }
        else {
            int prevMin = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if(s.empty()) {
            return -1;
        }

        int curr = s.top();

        if(curr < mini) {
            return mini;
        }
        else {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty()) {
            return -1;
        }

        return mini;
    }
};

int main() {
    SpecialStack s;
    s.push(2);
    s.push(1);
    s.push(4);
    s.push(3);

    // cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.getMin() << endl;
}