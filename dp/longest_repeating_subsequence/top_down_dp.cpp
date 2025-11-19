#include<bits/stdc++.h>
using namespace std;

int helper(int i, int j, string s, vector<vector<int>> &memo) {
    if(i == 0 || j == 0)
        return 0;

    if(memo[i][j] != -1)
        return memo[i][j];

    if(s[i - 1] == s[j - 1] && i != j)
        return memo[i][j] = 1 + helper(i - 1, j - 1, s, memo);

    return memo[i][j] = max(helper(i - 1, j, s, memo), helper(i, j - 1, s, memo));
}

int longestRepeatingSubsequence(string s) {
    int n = s.length();
    vector<vector<int>> memo(n + 1, vector<int> (n + 1, -1));
    
    return helper(n, n, s, memo);
}

int main() {
  
    string s = "AABEBCDD";
    int res = longestRepeatingSubsequence(s);
    cout << res;

    return 0;
}