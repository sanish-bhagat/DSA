#include <bits/stdc++.h>
using namespace std;

string firstNonRepeating(string &s)
{
    // freq hashmap
    unordered_map<char, int> freq;

    // stores non repeating chars
    queue<char> q;

    string res = "";

    // iterate through every letters
    for (char ch : s)
    {
        // update the freq count of the letter
        freq[ch]++;

        // push in the queue
        q.push(ch);

        // remove repeating letters, as they are of no use
        while (!q.empty() && freq[q.front()] > 1)
            q.pop();

        // no elements left in the queue -> all repeating letter, add "#" to res
        if (q.empty())
            res += "#";

        // non repeating char -> add "#" to the res
        else
            res += q.front();
    }

    return res;
}

int main()
{
    string s = "aabc";

    string res = firstNonRepeating(s);

    for (char ch : res)
        cout << ch;
}