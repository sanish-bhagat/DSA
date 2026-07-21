#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxIndexDiff(string &s)
{
    int n = s.size();

    // keep track of the farthest index reachable for every letter
    vector<int> lastIndex(26, -1);

    int ans = -1;

    // process from right to left, to consider jumps happens to only right
    for (int i = n - 1; i >= 0; i--)
    {
        int farthest = i;

        int currIdx = s[i] - 'a', nextIdx = s[i] - 'a' + 1;

        // if next letter is reachable -> make a jump
        if (s[i] != 'z' && lastIndex[nextIdx] != -1)
            farthest = lastIndex[nextIdx];

        // store the best max index reachable
        lastIndex[currIdx] = max(lastIndex[currIdx], farthest);

        // starting point can only be 'a'
        if (s[i] == 'a')
            ans = max(ans, farthest - i);
    }

    return ans;
}

int main()
{
    string s = "aaabcb";
    cout << maxIndexDiff(s);
}