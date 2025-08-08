#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n!)
//! SC is O(n)

void generatePermutation(int n, string &curr, vector<string> &res, unordered_map<char, int> &freq)
{

    // base case : agar permutation string ka size == given string ka size then res[] mein push krrdo
    if (curr.size() == n)
    {
        res.push_back(curr);
        return;
    }

    for (auto it : freq)
    {

        char ch = it.first;
        int count = it.second;

        // skip char with freq count 0
        if (count == 0)
            continue;

        curr.push_back(ch);

        // decrease the freq count
        freq[ch]--;

        // recursive call
        generatePermutation(n, curr, res, freq);

        // backtrack
        curr.pop_back();
        freq[ch]++;
    }
}

vector<string> findPermutation(string s)
{

    vector<string> res;
    unordered_map<char, int> freq;

    for (auto i : s)
        freq[i]++;

    string curr = "";
    generatePermutation(s.size(), curr, res, freq);

    return res;
}

int main()
{
    string s = "ABC";
    vector<string> res = findPermutation(s);

    // Print the permutations
    for (string perm : res)
        cout << perm << " ";

    return 0;
}
