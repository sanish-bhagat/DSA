#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int optimalKeys(int n)
{
    // The optimal string length is n when n is smaller than 7
    if (n <= 6)
        return n;

    // An array to store result of subproblems
    int screen[n];

    // Initialize the optimal lengths array for up to 6 keystrokes
    for (int i = 1; i <= 6; i++)
        screen[i - 1] = i;

    // Solve all subproblems in a bottom-up manner
    for (int i = 7; i <= n; i++)
    {

        // For any keystroke n, calculate the maximum of:
        // 1. Pressing Ctrl-V once after copying the A's
        //    obtained by (n-3) keystrokes.
        // 2. Pressing Ctrl-V twice after copying the A's
        //    obtained by (n-4) keystrokes.
        // 3. Pressing Ctrl-V thrice after copying the A's
        //    obtained by (n-5) keystrokes.
        screen[i - 1] = max(2 * screen[i - 4],
                            max(3 * screen[i - 5],
                                4 * screen[i - 6]));
    }

    return screen[n - 1];
}

int main()
{
    int n = 7;
    cout << optimalKeys(n) << endl;

    return 0;
}