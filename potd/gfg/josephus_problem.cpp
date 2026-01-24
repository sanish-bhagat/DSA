#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int josephus(int n, int k)
{
    // base case: only one person -> survivor is that only remaining person
    int ans = 0;

    // find the survivor by eliminating all the persons everytime in k steps
    for (int i = 2; i <= n; i++)
        ans = (ans + k) % i;

    // return the survivor as 1-based
    return ans + 1;
}

int main()
{
    int n = 5, k = 2;
    cout << josephus(n, k);
}