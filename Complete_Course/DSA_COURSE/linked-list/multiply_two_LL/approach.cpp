#include <iostream>
using namespace std;

long long MOD = 1000000007;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

//! TC is O(max(n1, n2))
//! SC is O(1)

long long multiplyTwoLists(Node *first, Node *second)
{
    long long num1 = 0, num2 = 0;

    //convert the LL into number
    while (first)
    {
        num1 = (num1 * 10 + first->data) % MOD;
        first = first->next;
    }

    //convert the LL into number
    while (second)
    {
        num2 = (num2 * 10 + second->data) % MOD;
        second = second->next;
    }

    //multiply the numbers and do modulo so that it remains within a safe range and the multiplication does not overflow
    return (num1 * num2) % MOD;
}

void printList(Node *curr)
{
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{

    // Create first list 9->4->6
    Node *head1 = new Node(9);
    head1->next = new Node(4);
    head1->next->next = new Node(6);

    // Create second list 8->4
    Node *head2 = new Node(8);
    head2->next = new Node(4);
    cout << multiplyTwoLists(head1, head2) << endl;

    return 0;
}