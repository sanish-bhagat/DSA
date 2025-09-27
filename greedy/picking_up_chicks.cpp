#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

pair<int, int> minSwaps(int N, int K, int B, int T, vector<int> &X, vector<int> &V)
{
    int reached = 0, obstacles = 0, swaps = 0;

    // traverse from right to left(closest to barn first)
    for (int i = N - 1; i >= 0; i--)
    {
        // if the i-th chick can reach the barn, then increase the reached count and
        // add obstacles encountered so far(slower chicks ahead) to swaps
        if (X[i] + V[i] * T >= B)
        {
            reached++;
            swaps += obstacles;

            // if K chicks have reached, we are done
            if (reached == K)
                break;
        }

        // increase the obstacles count for the slower chicks
        else
        {
            obstacles++;
        }
    }

    if (reached < K)
        return {-1, obstacles};

    return {swaps, obstacles};
}

int main()
{
    int N, K, B, T;
    cin >> N >> K >> B >> T;

    vector<int> X(N), V(N);

    for (int i = 0; i < N; i++)
        cin >> X[i];
    for (int i = 0; i < N; i++)
        cin >> V[i];

    auto res = minSwaps(N, K, B, T, X, V);

    if (res.first == -1)
    {
        cout << "Impossible\n";
    }
    else
    {
        cout << "Swaps: " << res.first << endl;
        cout << "Obstacles: " << res.second << endl;
    }
}