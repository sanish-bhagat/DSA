#include <bits/stdc++.h>
using namespace std;

// check if the string is palindrome or not
bool isPalindrome(string s)
{
    int n = s.size();

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }

    return true;
}

//! TC is O(n * (l ^ 2)), l = length of longest string in arr
//! SC is O(n * (l ^ 2))

bool palindromePair(vector<string> &arr)
{
    // hashmap, stores substring of all words in reverse order along with their indices
    unordered_map<string, int> mp;

    // build the hashmap
    for (int i = 0; i < arr.size(); i++)
    {
        string word = arr[i];
        reverse(word.begin(), word.end());
        mp[word] = i;
    }

    // iterate through all words
    for (int i = 0; i < arr.size(); i++)
    {
        // left substring
        string left = "";

        // for all characters
        for (int j = 0; j < arr[i].size(); j++)
        {
            // include the curr char in curr substring
            left += arr[i][j];

            // remaning substring
            string right = arr[i].substr(j + 1);

            // if left part is palindrome and right(reverse substring part) exists in hashmap -> return true
            if (!left.empty() && isPalindrome(left) && mp.count(right) && mp[right] != i)
                return true;

            // check the same by swapping thw left word and right
            if (isPalindrome(right) && mp.count(left) && mp[left] != i)
                return true;
        }
    }

    // no palindrome pair found
    return false;
}

int main()
{
    vector<string> arr = {"geekf", "geeks", "or", "keeg", "abc", "bc"};
    if (palindromePair(arr))
        cout << "True";
    else
        cout << "False";
    return 0;
}