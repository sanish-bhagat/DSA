#include<bits/stdc++.h>
using namespace std;

//! TC is O(n * n * n)
//! SC is O(1)

bool isPalindrome(string &str, int low, int high) {

    while(low < high) {

        if(str[low++] != str[high--])
            return false;
    }

    return true;
}

string longestPalindrome(string &str) {

    int n = str.length();
    int maxLen = 1, start = 0;

    for(int i = 0;i<n; i++) {

        for(int j = i; j<n; j++) {

            if(isPalindrome(str, i, j) && (j - i + 1) > maxLen) {
                start = i;
                maxLen = j - i + 1;
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