#include <bits/stdc++.h>
using namespace std;

//! Approach 1 =>
// create an array
// push all the elements of k-arrays into the created array  (O(n*k))
// sort them (O(n*k logn*k))

class Node
{
public:
    int data;
    int i;
    int j;

    Node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

//! TC is O(n*k log k)
//! SC is O(n*k)
vector<int> mergeKsortedArrays(vector<vector<int>> &arr, int k)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    // step1 - saare arrays k first element insert krrdo
    // O(k * log k)
    for (int i = 0; i < k; i++)
    {
        Node *temp = new Node(arr[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // step 2 -
    // O(n*k)
    while (minHeap.size() > 0)
    {
        Node *temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        if (j + 1 < arr[i].size())
        {
            // jo inserted array ka element h ussi element ka next bhi push krrdo
            Node *next = new Node(arr[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> v1 = {{3, 5, 9},
                              {1, 2, 3, 8}};

    vector<int> res = mergeKsortedArrays(v1, 2);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}