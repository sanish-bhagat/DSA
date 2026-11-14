#include <bits/stdc++.h>
using namespace std;

//! TC is O(n1 + n2 + n3)
//! SC is O(1)

int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3)
{
    // calculate the sum of all individual stack
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (int x : s1)
        sum1 += x;

    for (int x : s2)
        sum2 += x;

    for (int x : s3)
        sum3 += x;

    // ptrs to traverse the stack
    int top1 = 0, top2 = 0, top3 = 0;

    while (true)
    {
        // base case, either of the stack is empty
        if (top1 == s1.size() || top2 == s2.size() || top3 == s3.size())
            return 0;

        // return the equal sum
        if (sum1 == sum2 && sum2 == sum3)
            return sum1;

        // stack1's sum is max -> pop the top and try to make it equal to others
        if (sum1 >= sum2 && sum1 >= sum3)
            sum1 -= s1[top1++];

        // stack2's sum is max
        else if (sum2 >= sum1 && sum2 >= sum3)
            sum2 -= s2[top2++];

        // stack3's sum is max
        else
            sum3 -= s3[top3++];
    }
}

int main()
{
    vector<int> s1 = {3, 2, 1, 1, 1}, s2 = {4, 3, 2}, s3 = {2, 5, 4, 1};
    cout << maxEqualSum(s1, s2, s3);
}