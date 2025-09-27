#include <bits/stdc++.h>
using namespace std;

//! TC is O(n1 + n2 + n3)
//! SC is O(1)

int maxSum(vector<int> &s1, vector<int> &s2, vector<int> &s3)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;

    // find the sum of all elements of individual stacks
    for (int x : s1)
        sum1 += x;

    for (int y : s2)
        sum2 += y;

    for (int z : s3)
        sum3 += z;

        
    // top ptrs for different stacks
    int top1 = 0, top2 = 0, top3 = 0;

    // find the max equal sum
    while (true)
    {
        // if any stack becomes empty, after popping steps
        if (top1 == s1.size() || top2 == s2.size() || top3 == s3.size())
            return 0;

        // max equal sum
        if (sum1 == sum2 && sum2 == sum3)
            return sum1;

        // stack1's elements sum is max, pop the top of this stack
        if (sum1 >= sum2 && sum1 >= sum3)
            sum1 -= s1[top1++];

        // else, stack2's elements sum is max, pop the top of this stack
        else if (sum2 >= sum1 && sum2 >= sum3)
            sum2 -= s2[top2++];

        // or else, stack3's elements sum is max, pop the top of this stack
        else
            sum3 -= s3[top3++];
    }
}

int main()
{
    vector<int> s1 = {3, 2, 1, 1, 1};
    vector<int> s2 = {4, 3, 2};
    vector<int> s3 = {1, 1, 4, 1};

    cout << maxSum(s1, s2, s3) << endl;
    return 0;
}