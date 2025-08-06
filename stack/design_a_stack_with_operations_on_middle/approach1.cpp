#include <bits/stdc++.h>
using namespace std;

//! deleting of the middle element can be done in O(n) time

class myStack
{
    struct Node
    {
        int data;
        Node *next;
        Node *prev;

        Node(int data)
        {
            this->data = data;
            next = NULL;
            prev = NULL;
        }
    };

    Node *mid;
    Node *head;

public:
    int size = 0;

    void push(int data)
    {
        Node *temp = new Node(data);

        if (size == 0)
        {
            head = temp;
            mid = temp;
            size++;
            return;
        }

        head->next = temp;
        temp->prev = head;
        head = head -> next;
        if (size % 2 == 1)
            mid = mid->next;

        size++;
    }

    int pop()
    {
        int val = -1;
        if (size != 0)
        {
            Node *topNode = head;
            val = topNode->data;

            if (size == 1)
            {
                head = NULL;
                mid = NULL;
            }
            else
            {
                head = head->prev;
                head->next = NULL;

                if (size % 2 == 0) {
                    mid = mid->prev;
                }
            }

            delete topNode;
            size--;
        }

        return val;
    }

    int findMiddle() {
        if(size == 0)
            return -1;
        
        return mid -> data;
    }

    void deleteMiddle() {
        if(size != 0) {

            Node *toDelete = mid;
            
            if(size == 1) {
                head = NULL;
                mid = NULL;
            }
            else if(size == 2) {
                head = head -> prev;
                mid = mid -> prev;
                head -> next = NULL;
            }
            else {
                mid -> next -> prev = mid -> prev;
                mid -> prev -> next = mid -> next;

                if(size % 2 == 0)
                    mid = mid -> prev;
                else
                    mid = mid -> next;
            }
            delete toDelete;
            size--;
        }
    }
};

int main()
{
    myStack st;
    st.push(0);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "Size of stack is: " << st.size << endl;
    cout << "Popped element is: " << st.pop() << endl;
    cout << "Size of stack is: " << st.size << endl;
    cout << "Middle element is: " << st.findMiddle() << endl;
    st.deleteMiddle();
    cout << "Size of stack is: " << st.size << endl;
    
}