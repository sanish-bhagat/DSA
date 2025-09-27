#include <bits/stdc++.h>
using namespace std;

//! TC is O(1)
//! SC is O(1)

int survival(int S, int N, int M)
{
    // check if the survival is possible or not
    if (((N * 6) < (M * 7) && S > 6) || M > N)
        return -1;

    // if we can survive
    else
    {
        int days = (M * S) / N;

        if ((M * S) % N != 0)
            days++;

        return days;
    }
}

int main()
{
    int S = 10, N = 16, M = 2;
    cout << survival(S, N, M);
    return 0;
}