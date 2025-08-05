#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

//global variable to track min element
int minEle;

void push(stack<int> &s, int a) {
    if(s.empty()) {
        s.push(a);
        minEle = a;
    }
    else {
        if(a > minEle) {
            s.push(a);
        }
        else {  //a < minEle
            //encoded value is pushed
            s.push(2*a - minEle);
            minEle = a;
        }
    }
}

int pop(stack<int> &s) {
    if(s.empty())
        return -1;
    
    int top = s.top();
    s.pop();

    if(top > minEle) {
        return top;
    }
    else{
        //store the prevMin
        int prevMin = minEle;

        //update the minEle
        minEle = 2 *minEle - top;
        return prevMin;
    }
}

bool isFull(stack<int> &s, int n) {
    return s.size() == n;
}

bool isEmpty(stack<int> &s) {
    return s.empty();
}

int getMin(stack<int> &s) {
    if(s.empty()) 
        return -1;
    
    return minEle;
}

int main()
{
    stack<int> s;
    push(s, 5); // minEle = 5
    push(s, 3); // minEle = 3, encoded push
    push(s, 7); // minEle = 3
    cout << "Min element is: " << getMin(s) << endl;  // returns 3
    cout << "Popped value is: " << pop(s) << endl;     // pops 7
    cout << "Min element is: " << getMin(s) << endl;  // still 3
    cout << "Popped value is: " << pop(s) << endl;     // pops 3, decodes and updates minEle = 5
    cout << "Min element is: " << getMin(s) << endl;  // now returns 5
}