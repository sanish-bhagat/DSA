#include <bits/stdc++.h>
using namespace std;

// helper function to return true if string contains valid parantheses
bool isValid(string &s)
{
    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            cnt++;

        else if (s[i] == ')')
            cnt--;

        if (cnt < 0)
            return false;
    }

    return (cnt == 0);
}

//! TC is O(2 ^ n)
//! SC is O(2 ^ n)

vector<string> validParantheses(string &s)
{
    // to track the visited string
    unordered_set<string> visit;

    // to maintain BFS order
    queue<string> q;

    vector<string> res;
    bool level = false;

    // push the given string as starting node
    q.push(s);

    // mark the string as visited
    visit.insert(s);

    while (!q.empty())
    {
        string temp = q.front();
        q.pop();

        // if string is valid
        if (isValid(temp))
        {
            // store it
            res.push_back(temp);

            // mark level true, so that valid string of only that level are processed
            level = true;
        }

        if (level)
            continue;

        for (int i = 0; i < temp.size(); i++)
        {
            // if curr character is not a parantheses, continue to next character
            if (temp[i] != ')' && temp[i] != '(')
                continue;

            // remove paranthese from string and pushing it into the queue, if not visited already
            string curr = temp.substr(0, i) + temp.substr(i + 1);
            if (!visit.count(curr))
            {
                q.push(curr);
                visit.insert(curr);
            }
        }
    }

    return res;
}

int main()
{
    string s = "()(l()((";
    vector<string> res = validParantheses(s);

    for (string x : res)
        cout << x << " ";
}