#include <bits/stdc++.h>
using namespace std;

int findSqrt(int n)
{
    int ans = 1;

    for (int i = 0; i <= n; i++)
    {
        if (i * i <= n)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the element: ";
    cin >> n;

    cout << findSqrt(n);
}