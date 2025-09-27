#include <bits/stdc++.h>
using namespace std;

string findKthPermutation(int n, int k)
{
    // generate the numbers 1..n
    vector<int> nums;
    for (int i = 1; i <= n; i++)
        nums.push_back(i);

    // precompute factorials upto n
    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i;

    // convert k to 0-based index (since permutations are 1-indexed)
    k--;

    // ans string
    string ans = "";

    // build the permutation digit by digit
    for (int i = n; i >= 1; i--)
    {
        // find which block (group of permutations) k lies in -> tells us which no. to pick
        int idx = k / fact[i - 1];

        // update k inside the grp
        k = k % fact[i - 1];

        // pick the no.
        ans += to_string(nums[idx]);

        // remove the already chosen digit
        nums.erase(nums.begin() + idx);
    }

    return ans;
}

int main()
{
    int n = 3, k = 4;

    // function call
    string kth_perm_seq = findKthPermutation(n, k);
    cout << kth_perm_seq << endl;

    return 0;
}