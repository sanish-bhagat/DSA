#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

vector<vector<int>> levelSort(vector<int> &arr)
{
    int n = arr.size();

    if (n == 0)
        return {};

    vector<vector<int>> res;

    // queue for level order traversal, store indices
    queue<int> q;

    // push the root node index
    q.push(0);

    while (!q.empty())
    {
        vector<int> currLvl;
        int size = q.size();

        // visit all the nodes in the curr level
        for (int i = 0; i < size; i++)
        {
            int node = q.front();
            q.pop();

            currLvl.push_back(arr[node]);

            // push the left child index
            if (2 * node + 1 < n)
                q.push(2 * node + 1);

            // push the right child index
            if (2 * node + 2 < n)
                q.push(2 * node + 2);
        }

        // sort the nodes in the curr level
        sort(currLvl.begin(), currLvl.end());

        res.push_back(currLvl);
    }

    return res;
}

int main()
{
    vector<int> arr = {7, 6, 5, 4, 3, 2, 1};

    vector<vector<int>> result = levelSort(arr);

    // Print level by level
    for (auto &level : result)
    {
        for (int value : level)
        {
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}