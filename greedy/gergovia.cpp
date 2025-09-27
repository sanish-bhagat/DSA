#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int main()
{
    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long balance = 0, work = 0;

    for (int i = 0; i < n; i++)
    {
        // balance represents how many bottles must be transported from house i to house (i + 1)
        balance += a[i];

        // amount of work required at each step
        work += abs(balance);
    }

    // balance will always be 0 (demand = supply)
    cout << "Balance: " << balance << endl;
    cout << "Work: " << work << endl;
}