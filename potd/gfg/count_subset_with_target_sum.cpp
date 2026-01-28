#include <bits/stdc++.h>
using namespace std;

class Solution
{

    void genSum(int i, int end, int sum, vector<int> &arr, vector<long long> &v)
    {
        // push the curr subset sum
        if (i == end)
        {
            v.push_back(sum);
            return;
        }

        // skip element
        genSum(i + 1, end, sum, arr, v);

        // take element
        genSum(i + 1, end, sum + arr[i], arr, v);
    }

public:
    // !TC is O(2 ^ (n / 2))
    //! SC is O(n)
    int countSubset(vector<int> &arr, int k)
    {
        int n = arr.size();

        // middle boundary to separate arr[] in two halves
        int mid = n / 2;

        // 1d[] for two halves
        vector<long long> left, right;

        // generate subsets sum for each half
        genSum(0, mid, 0, arr, left);
        genSum(mid, n, 0, arr, right);

        // map every subset sum of right half ->
        // makes easier to find if (k - l) is present in right half or not
        unordered_map<long long, long long> mp;
        for (auto x : right)
            mp[x]++;

        long long ans = 0;

        // count all subsets (l + r == k)
        for (auto x : left)
            ans += mp[k - x];

        return ans;
    }
};

int main()
{
    int k = 3;
    vector<int> arr = {1, 3, 2};

    Solution s = Solution();

    cout << s.countSubset(arr, k);
}