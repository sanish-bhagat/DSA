#include <bits/stdc++.h>
using namespace std;

// precompute factorial upto given n
vector<int> computeFact(int n)
{
    vector<int> fact(n + 1);

    fact[0] = 1;

    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i;

    return fact;
}

// compute the nth catalan no. using the precomputed factorials
int catalan(int n, vector<int> &fact)
{
    return fact[2 * n] / (fact[n] * fact[n + 1]);
}

vector<int> countBSTs(vector<int> &arr)
{
    int n = arr.size();

    // store the elements along with their index
    vector<vector<int>> sorted;
    for (int i = 0; i < n; i++)
        sorted.push_back({arr[i], i});

    // sort based on the values
    sort(sorted.begin(), sorted.end());

    // precompute factorial upto 2*n
    vector<int> fact = computeFact(2 * n);

    vector<int> numBsts(n);

    // compute BST count for each element as root
    for (int i = 0; i < n; i++)
    {
        int j = sorted[i][1];

        numBsts[j] = catalan(i, fact) * catalan(n - i - 1, fact);
    }

    return numBsts;
}

int main()
{
    vector<int> arr = {2, 1, 3};

    vector<int> numBSTs = countBSTs(arr);
    for (int val : numBSTs)
        cout << val << " ";
    cout << endl;

    return 0;
}