#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n * n)

vector<vector<int>> formCoils(int n)
{
    int m = 8 * n * n;
    vector<int> coil1(m), coil2(m);

    coil1[0] = 8 * n * n + 2 * n;
    int curr = coil1[0];

    int flag = 1, step = 2;
    int index = 1;

    // Generate the standard first coil.
    while (index < m)
    {
        for (int i = 0; i < step && index < m; i++)
            curr = coil1[index++] = curr - 4 * n * flag;

        for (int i = 0; i < step && index < m; i++)
            curr = coil1[index++] = curr + flag;

        flag *= -1;
        step += 2;
    }

    // Generate the second coil using complementary values.
    for (int i = 0; i < m; i++)
        coil2[i] = 16 * n * n + 1 - coil1[i];

    // Reverse the standard order to match the required output.
    reverse(coil1.begin(), coil1.end());
    reverse(coil2.begin(), coil2.end());

    return {coil2, coil1};
}

int main()
{
    int n = 1;

    vector<vector<int>> ans = formCoils(n);

    cout << "[";
    for (int i = 0; i < 2; i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j + 1 < ans[i].size())
                cout << ", ";
        }
        cout << "]";
        if (i == 0)
            cout << ", ";
    }
    cout << "]";

    return 0;
}