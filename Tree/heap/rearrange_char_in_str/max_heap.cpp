#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

string rearrangeString(string &s)
{
    int n = s.length();

    // generate the freq of all char of the string
    unordered_map<char, int> freq;

    for (int i = 0; i < n; i++)
        freq[s[i]]++;

    // max heap -> for the char on basis of their freq
    priority_queue<pair<int, char>> pq;

    for (char c = 'a'; c <= 'z'; c++)
    {
        if (freq[c] > 0)
            pq.push({freq[c], c});
    }

    // temp variable, for prev char
    pair<int, char> prev = {-1, '#'};

    string res = "";

    while (!pq.empty())
    {
        // get the top
        pair<int, char> top = pq.top();
        pq.pop();

        // push the top char into res
        res.push_back(top.second);

        // if the prev char freq is still greater than 0 then push it in the heap
        if (prev.first > 0)
            pq.push(prev);

        // decrement the freq count  of the curr char
        top.first--;

        // store the curr char into the prev, so that the curr doesn't repeat on the very next time
        prev = top;
    }

    if (res.size() != n)
        return "";

    return res;
}

int main()
{
    string s = "aaabc";
    cout << rearrangeString(s);
    return 0;
}