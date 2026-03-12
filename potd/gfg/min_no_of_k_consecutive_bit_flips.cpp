#include <bits/stdc++.h>
using namespace std;

int kBitFlips(vector<int> &arr, int k)
{
    int n = arr.size();
    
    // flag tells whether the curr element is in a flipped state
    int flag = 0, res = 0;

    // queue used to track active flips
    queue<int> q;

    for (int i = 0; i < n; i++)
    {

        // remove the effect of the flip that started k steps ago
        if (i >= k)
        {
            flag ^= q.front();
            q.pop();
        }

        // flip the curr element
        if (flag == 1)
            arr[i] ^= 1;

        // arr[i] = 0 -> then we need to flip
        if (arr[i] == 0)
        {

            // out of index element
            if (i + k > n)
                return -1;

            // increment the flip count
            res++;

            // flip the flag for the upcoming elements
            flag ^= 1;

            // if we flip -> push 1 to queue
            q.push(1);
        }

        // if we don't flip -> push 0 to queue
        else
            q.push(0);
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1};
    int k = 2;
    cout << kBitFlips(arr, k);
    return 0;
}