#include <bits/stdc++.h>
using namespace std;

// check if segment is a valid IP part
bool isValid(string &s)
{
    // leading zeros not allowed
    if (s.size() > 1 && s[0] == '0')
        return false;

    // first char of the string should range from (0...255), no leading zeros
    int val = stoi(s);
    return val <= 255;
}

// recursive function to generate IP address
void generateIpRec(string &s, int index, string curr, int cnt, vector<string> &res)
{
    // base case
    if (index >= s.size())
        return;

    // 3 dots are placed, then valid the last segment of
    if (cnt == 3)
    {
        string last = s.substr(index);

        // valid last segment -> include in the res
        if (last.size() <= 3 && isValid(last))
            res.push_back(curr + last);

        return;
    }

    string segment = "";

    // try segement lengths 1 to 3
    for (int i = index; i < min(index + 3, (int)s.size()); i++)
    {
        segment += s[i];

        // valid segment -> recurse for the next segment
        if (isValid(segment))
            generateIpRec(s, i + 1, curr + segment + ".", cnt + 1, res);
    }
}

//! TC is O(n)
//! SC is O(ntop_))

vector<string> generateIp(string &s)
{
    vector<string> res;

    // generate all valid IP addresses
    generateIpRec(s, 0, "", 0, res);
    return res;
}

int main()
{
    string s = "255678166";
    vector<string> res = generateIp(s);

    for (string ip : res)
        cout << ip << endl;
}