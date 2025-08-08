#include <bits/stdc++.h>
using namespace std;

//! TC is O(2 ^ n)
//! SC is O(n)

void subsetSumsRec(vector<int> arr, int index, int currSum, vector<int> &res)
{

    // base case
    if (index == arr.size())
    {
        res.push_back(currSum);
        return;
    }

    // include the curr element
    subsetSumsRec(arr, index + 1, currSum + arr[index], res);

    // exclude the curr element
    subsetSumsRec(arr, index + 1, currSum, res);
}

vector<int> subsetSums(vector<int> arr)
{
    vector<int> res;
    subsetSumsRec(arr, 0, 0, res);

    return res;
}

int main()
{
    vector<int> arr = {5, 4, 3};
    vector<int> result = subsetSums(arr);

    cout << "Subset Sums: ";
    for (int sum : result)
    {
        cout << sum << " ";
    }

    return 0;
}