#include <bits/stdc++.h>
using namespace std;

// TC is O(N*M)

int mul(int n, int m)
{
    int res = 1;
    for (int i = 1; i <= m; i++)
    {
        res *= n;
    }
    return res;
}

int nThRoot(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        if (mul(i, m) == n)
        {
            return i;
        }
        else if (mul(i, m) > n)
        {
            break;
        }
    }
    return -1;
}

int main()
{
    int n, m;
    cout << "Enter the element: ";
    cin >> n;

    cout << "Enter the no. of square root: ";
    cin >> m;

    cout << nThRoot(n, m);
}