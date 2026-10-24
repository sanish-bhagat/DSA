#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

bool isPossible(int n, int m, string s)
{
    // start from cell (0, 0)
    int i = 0, j = 0;

    // keep track of max and min row and col visited till now
    int minRow = 0, maxRow = 0, minCol = 0, maxCol = 0;

    for (char c : s)
    {
        // perform the moving direction
        if (c == 'L')
            j -= 1;

        else if (c == 'R')
            j += 1;

        else if (c == 'U')
            i -= 1;

        else
            i += 1;

        // update values
        minRow = min(minRow, i);
        minCol = min(minCol, j);

        maxRow = max(maxRow, i);
        maxCol = max(maxCol, j);

        // if we ever exceed the boundaries ->
        // it is impossible for the path too fit in the grid
        if ((maxRow - minRow + 1) > n || (maxCol - minCol + 1) > m)
            return false;
    }

    // we have performed all the operations without exceeding the boundaries
    return true;
}

int main()
{
    int n = 2, m = 3;
    string s = "LLRU";

    cout << isPossible(n, m, s);
}