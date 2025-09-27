#include<iostream>
#include<stack>
using namespace std;

class TwoStack {
    int *arr;
    int size;
    int top1;
    int top2;

    public:
        TwoStack(int s) {
            this -> size = s;
            top1 = -1;
            top2 = s;
            arr = new int[s];
        }

    void push1(int num) {
        if(top2 - top1 > 1) { //top1 < top2 - 1, it will check that if there is an empty space present or not
            top1++;
            arr[top1] = num;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    void push2(int num) {
        if(top2 - top1 > 1) { //top1 < top2 - 1
            top2--;
            arr[top2] = num;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    int pop1() {
        if(top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else {
            return -1;
        }
    }

    int pop2() {
        if(top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else {
            return -1;
        }
    }
};

int main() {
    TwoStack tst(5);

    tst.push1(1);
    tst.push1(2);
    tst.push1(3);
    tst.push2(5);
    tst.push2(4); 

    cout << "The popped element from stack1 is: " << tst.pop1() << endl;
    cout << "the popped element from stack2 is: " << tst.pop2();
}