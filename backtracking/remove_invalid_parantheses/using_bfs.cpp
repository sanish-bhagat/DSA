#include <bits/stdc++.h>
using namespace std;

// helper function to return true if string contains valid parantheses
bool isValidParenthesis(string &s)
{
    int cnt = 0;

    for (int i = 0; i < s.length(); i++)
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

vector<string> validParenthesis(string &str)
{
    // to track the visited string
    unordered_map<string, int> visit;

    // to maintain BFS order
    queue<string> q;

    vector<string> res;
    bool level = false;

    // push the given string as starting node
    q.push(str);

    // mark the string as visited
    visit[str] = 1;

    while (!q.empty())
    {
        string temp = q.front();
        q.pop();

        // if string is valid
        if (isValidParenthesis(temp))
        {
            // store it
            res.push_back(temp);

            // mark level true, so that valid string of only that level are processed
            level = true;
        }

        if (level)
            continue;

        for (int i = 0; i < temp.length(); i++)
        {
            // if curr character is not a parantheses, continue to next character
            if (temp[i] != '(' && temp[i] != ')')
                continue;

            // remove paranthese from string and pushing it into the queue, if not visited already
            string curr = temp.substr(0, i) + temp.substr(i + 1);
            if (visit.count(curr) == 0)
            {
                q.push(curr);
                visit[curr] = 1;
            }
        }
    }

    return res;
}

int main()
{
    string str = "(v)())()";
    vector<string> res = validParenthesis(str);
    for (string s : res)
    {
        cout << s << endl;
    }
    return 0;
}