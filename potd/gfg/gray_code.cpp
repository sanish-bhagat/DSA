#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * 2^n)
//! SC is O(1)

vector<string> grayCode(int n)
{
    vector<string> res;

    // generate all the combinations
    for (int i = 0; i < (1 << n); i++)
    {
        // generate the i-th gray code
        int g = i ^ (i >> 1);

        // convert the code into string
        string s = "";

        for (int j = n - 1; j >= 0; j--)
        {
            if (g & (1 << j))
                s += "1";

            else
                s += "0";
        }

        // push the converted string into the res[]
        res.push_back(s);
    }

    return res;
}

int main()
{
    int n = 3;
    vector<string> res = grayCode(n);

    for (string s : res)
        cout << s << " ";
}