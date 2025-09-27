#include <bits/stdc++.h>
using namespace std;

// TC is O(26 * N)
// SC is O(26)

string firstNonRepeating(string str)
{
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // increase count
        count[ch]++;

        // queue me push karo
        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                // repeating char
                q.pop();
            }
            else
            {
                // non-repeating char
                ans.push_back(q.front());
                break;
            }
        }
        
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    string str = "aabc";

    string ans = firstNonRepeating(str);

    for (int i = 0; i < ans.length(); i++)
    {
        cout << ans[i] << " ";
    }
}