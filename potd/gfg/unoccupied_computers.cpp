#include <bits/stdc++.h>
using namespace std;

//! TC is O(s.size())
//! SC is O(1)

int solve(int n, string &s)
{
    // status hashmap, 0 -> not arrived, 1 -> currently assigned, 2 -> rejected
    vector<int> status(26, 0);

    int cnt = 0, res = 0;

    for (char c : s)
    {
        // new customer arrival
        if (status[c - 'A'] == 0)
        {
            // can asssign a computer to the customer
            if (cnt < n)
            {
                status[c - 'A'] = 1;
                ;
                cnt++;
            }

            // reject the customer
            else
            {
                status[c - 'A'] = 2;
                res++;
            }
        }

        // customer departure
        else if (status[c - 'A'] == 1)
        {
            status[c - 'A'] = 0;
            cnt--;
        }
    }

    return res;
}

int main()
{
    int n = 2;
    string s = "EDCEDABACB";

    cout << solve(n, s);
}