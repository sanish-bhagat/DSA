#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

bool isPossible(int s, int x, vector<int> &arr)
{
    // sequence sum[]
    vector<long long> seq;

    // start from the given s
    seq.push_back(s);

    long long sum = s;

    for (int val : arr)
    {
        // add the curr val in the sequence
        long long curr = sum + val;
        seq.push_back(curr);

        // update prefix sum
        sum += curr;
    }

    // greedily subtract the largest possible values from target(x)
    for (int i = seq.size() - 1; i >= 0; i--)
    {
        if (seq[i] <= x)
            x -= seq[i];
    }

    // x can be formed
    return x == 0;
}

int main()
{
    int s = 1, x = 7;
    vector<int> arr = {1, 2, 4, 2};

    cout << isPossible(s, x, arr);
}