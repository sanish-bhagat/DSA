#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

//! TC is O(n * logn)
//! Sc is O(n)

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> ans;
    unordered_map<int, Node *> visited;

    Node *curr = head;

    while (curr != NULL)
    {
        int x = target - curr->data;

        if (visited.find(x) != visited.end())
            ans.push_back({x, curr->data});

        visited[curr->data] = curr;
        curr = curr->next;
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    // Create a doubly linked list: 1 <-> 2 <-> 4 <-> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

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