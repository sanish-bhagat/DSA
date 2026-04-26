#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    vector<int> res;

    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size() && k < c.size())
    {
        // equality check
        if (a[i] == b[j] && b[j] == c[k])
        {
            res.push_back(a[i]);
            i++, j++, k++;

            // skip duplicates
            while (i < a.size() && a[i] == a[i - 1])
                i++;
            while (j < b.size() && b[j] == b[j - 1])
                j++;
            while (k < c.size() && c[k] == c[k - 1])
                k++;
        }

        // move the ptr of the smallest among all three
        else if (a[i] < b[j])
            i++;

        else if (b[j] < c[k])
            j++;

        else
            k++;
    }

    return res;
}

int main()
{
    vector<int> a = {1, 5, 10, 20, 40, 80}, b = {6, 7, 20, 80, 100}, c = {3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> res = commonElements(a, b, c);

    for (int x : res)
        cout << x << " ";
}