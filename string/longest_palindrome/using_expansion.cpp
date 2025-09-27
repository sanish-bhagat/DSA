#include<bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

string longestPalindrome(string &str) {

    int n = str.length();

    if(n == 0)
        return "";

    int maxLen = 1, start = 0;

    for(int i = 0; i<n; i++) {

        //even and odd length palindromes k liye ye loop chlega
        for(int j = 0; j<= 1; j++) {

            int low = i, high = i + j;

            while(low >= 0 && high < n && str[low] == str[high]) {

                int currLen = high - low + 1;

                if(currLen > maxLen) {

                    start = low;
                    maxLen = currLen;
                }
                low--, high++;
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