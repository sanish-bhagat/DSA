#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)  , as the size of the vector is constant

string removeDuplicates(string &s)
{

    // freq array initialise krro
    vector<int> ch(256, 0);
    string ans = "";

    for (char c : s)
    {

        // if freq is 0, character is occured for the first time
        if (ch[c] == 0)
        {

            // ans string mein push krrdo
            ans.push_back(c);

            // freq increment krrdo
            ch[c]++;
        }
    }

    return ans;
}

int main()
{
    string s = "geeksforgeeks";
    cout << removeDuplicates(s) << endl;
    return 0;
}