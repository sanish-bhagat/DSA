#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n!)
//! SC is O(n!)

void generatePermutation(int index, string &s, vector<string> &res)
{

    // base case
    if (index == s.length())
    {
        res.push_back(s);
        return;
    }

    for (int i = index; i < s.length(); i++)
    {

        swap(s[index], s[i]);

        // recursive call
        generatePermutation(index + 1, s, res);

        // backtrack
        swap(s[index], s[i]);
    }
}

vector<string> findPermutation(string s)
{

    vector<string> res;

    generatePermutation(0, s, res);

    sort(res.begin(), res.end());

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
