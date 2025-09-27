#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

//! TC is O(n)
//! SC is O(1)

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{

    vector<pair<int, int>> res;
    Node *first = head, *second = head;

    while (second->next != NULL)
        second = second->next;

    while (first != second && second->next != first)
    {

        if ((first->data + second->data) == target)
        {
            res.push_back({first->data, second->data});
            first = first->next;
            second = second->prev;
        }
        else
        {
            if ((first->data + second->data) < target)
                first = first->next;

            else
                second = second->prev;
        }
    }

    return res;
}

int main()
{

    // Create a doubly linked list: 1 <-> 2 <-> 4 <-> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(5);
    head->next->next->next->prev = head->next->next;

    int target = 7;
    vector<pair<int, int>> pairs = findPairsWithGivenSum(head, target);

    if (pairs.empty())
    {
        cout << "No pairs found." << endl;
    }
    else
    {
        for (auto &pair : pairs)
        {
            cout << pair.first << " " << pair.second << endl;
        }
    }
    return 0;
}