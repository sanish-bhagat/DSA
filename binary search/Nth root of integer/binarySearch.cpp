#include <bits/stdc++.h>
using namespace std;

//return 1 if == n
//return 2 if > n
//return 0 if < n
//to avoid the oevrflow we will be doing this since we can end up getting a no. which is out of the range of long long or int

int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= m; i++)
    {
        ans *= mid;
        if (ans > n)
            return 2;
    }
    if (ans == n)
        return 1;
    return 0;
}

int nThRoot(int n, int m)
{
    int low = 1, high = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int midN = func(mid, n, m);

        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n, m;
    cout << "Enter the element: ";
    cin >> n;

    cout << "Enter the no.of times sqrt: ";
    cin >> m;

    cout << nThRoot(n,m);
}