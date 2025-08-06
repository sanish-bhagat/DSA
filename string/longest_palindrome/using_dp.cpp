#include<bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n * n)

int dp[1001][1001];

bool solve(string &s, int low, int high) {

    if(low >= high) {
        return 1;
    }

    if(dp[low][high] != -1)
        return dp[low][high];

    if(s[low]== s[high]) {
        return dp[low][high] = solve(s, low + 1, high - 1);
    }

    return dp[low][high] = 0;
}

string longestPalindrome(string &str) {

    int n = str.length();
    memset(dp, -1, sizeof(dp));

    int maxLen = INT_MIN, start = 0;

    for(int i = 0; i<n; i++) {

        for(int j = i; j<n; j++) {

            if(solve(str, i, j)) {

                if(j - i + 1 > maxLen) {
                    start = i, maxLen = j - i + 1;
                }
            }
        }
    }

    return str.substr(start, maxLen);
}

int main() {
    string str = "forgeeksskeegfor";
    cout << longestPalindrome(str) << endl;
    return 0;
}