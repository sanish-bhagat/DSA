#include <bits/stdc++.h>
using namespace std;

// struct Node {
//     int val, row, col;
// };

// struct Compare {
//     bool operator()(const Node& a, const Node& b) const {
//         return a.val > b.val;  // for min-heap
//     }
// };

// // Use with:
// priority_queue<Node, vector<Node>, Compare> minHeap;

struct Node
{
    int val, row, col;

    bool operator>(const Node &other) const
    {
        return val > other.val;
    }
};

//! TC is O(n * k * logk)
//! SC is O(k)

vector<int> findSmallestRange(vector<vector<int>> &arr)
{
    int k = arr.size();

    int minRange = INT_MAX;
    int minEle, maxEle;
    int maxVal = INT_MIN;

    // min heap
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // push the first elmement of every list and also get the max of them
    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i][0], i, 0});
        maxVal = max(maxVal, arr[i][0]);
    }

    while (true)
    {
        // min node
        Node curr = pq.top();
        pq.pop();

        // curr min val
        int minVal = curr.val;

        // update the minrange if smaller range is found, (max - min) < minRange
        if (maxVal - minVal < minRange)
        {
            minRange = maxVal - minVal;
            minEle = minVal;
            maxEle = maxVal;
        }

        // if reached the end of the list, break
        if (curr.col + 1 == k)
            break;

        // push the nextVal into the min-heap, and update the maxVal
        int nextVal = arr[curr.row][curr.col + 1];
        pq.push({nextVal, curr.row, curr.col + 1});
        maxVal = max(maxVal, nextVal);
    }

    // return the smallest range
    return {minEle, maxEle};
}

int main()
{

    vector<vector<int>> arr = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}};

    vector<int> res = findSmallestRange(arr);

    cout << res[0] << " " << res[1];

    return 0;
}