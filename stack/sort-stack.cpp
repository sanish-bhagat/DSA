#include<iostream>
#include<stack>
using namespace std;

//TC is O(n * n)

void sortedInsert(stack<int> &stack, int num) {

    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num)) {
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    //recursive call
    sortedInsert(stack, num);

    stack.push(n);
}

void sortStack(stack<int> &stack) {

    //base case
    if(stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();

    //recursive call
    sortStack(stack);

    sortedInsert(stack, num);
}

int main() {
    stack<int> s;
    s.push(2);
    s.push(1);
    s.push(6);
    s.push(8);
    s.push(5);

    sortStack(s);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}