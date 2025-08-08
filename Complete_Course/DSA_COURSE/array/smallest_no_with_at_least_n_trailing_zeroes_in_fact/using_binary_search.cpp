#include <bits/stdc++.h>
using namespace std;

//! TC is O(log n * log n)
//! SC is O(1)

bool check(int p, int n)
{
    int temp = p, cnt = 0, f = 5;

    while (f <= temp)
    {
        cnt += temp / f;
        f *= 5;
    }

    return (cnt >= n);
}

int findNum(int n)
{

    if (n == 1)
        return 5;

    int low = 0, high = 5 * n;

    while (low < high)
    {

        int mid = (low + high) >> 1; //(low + high) / 2

        if (check(mid, n))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{
    int n = 6;
    cout << findNum(n) << endl;
    return 0;
}