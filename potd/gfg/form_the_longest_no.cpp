#include <bits/stdc++.h>
using namespace std;

// sort the concatenation of strings in descending order
bool myCompare(string &s1, string &s2)
{
    return (s1 + s2) > (s2 + s1);
}

string findLargest(vector<int> &arr)
{
    vector<string> nums;

    // store the elements of the given arr[] as string
    for (int x : arr)
        nums.push_back(to_string(x));

    // sort the strings in descending order based on the concatenation
    sort(nums.begin(), nums.end(), myCompare);

    // all numbers are 0 -> since we are sorting in descending order
    if (nums[0] == "0")
        return "0";

    // build the res by concatenating the sorted nums[]
    string res = "";
    for (string s : nums)
        res.append(s);

    return res;
}

int main()
{
    vector<int> arr = {3, 30, 34, 5, 9};
    cout << findLargest(arr);
}