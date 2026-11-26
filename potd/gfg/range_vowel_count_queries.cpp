#include <bits/stdc++.h>
using namespace std;

vector<int> countVowels(string &s, vector<vector<int>> &queries)
{
    int n = s.size();

    // stores the no. of vowels occuring till index (i - 1)
    vector<int> prefix(n + 1, 0);
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        // character is a vowel -> increment the count
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            prefix[i + 1] = prefix[i] + 1;

        else
            prefix[i + 1] = prefix[i];
    }

    for (auto q : queries)
    {
        int l = q[0], r = q[1];

        // calculate the no. of vowels in each substring
        ans.push_back(prefix[r + 1] - prefix[l]);
    }

    return ans;
}

int main()
{
    string s = "geeksforgeeks";
    vector<vector<int>> queries = {{1, 3}, {2, 4}, {1, 9}};

    vector<int> ans = countVowels(s, queries);

    // Print the results for all queries.
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        if (i > 0)
            cout << ", ";
        cout << ans[i];
    }
    cout << "]" << endl;

    return 0;
}