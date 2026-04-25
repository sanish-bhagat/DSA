#include <bits/stdc++.h>
using namespace std;

vector<int> reducePairs(vector<int> &arr)
{
    vector<int> res;

    for (int i = 0; i < arr.size(); i++)
    {
// push curr element
        res.push_back(arr[i]);

        while (res.size() >= 2)
        {
            // pop the two adjacent elements
            int a = res.back();
            res.pop_back();
            int b = res.back();
            res.pop_back();

            // opposite sign -> push the one which have larger absolute value into the res[] back
            if ((a > 0 && b < 0) || (a < 0 && b > 0))
            {
                if (abs(a) > abs(b))
                    res.push_back(a);

                else if (abs(a) < abs(b))
                    res.push_back(b);
            }

            // same sign, push back into the res[], restoring the correct order
            else
            {
                res.push_back(b);
                res.push_back(a);
                break;
            }
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {10, -5, -8, 2, -5};

    vector<int> res = reducePairs(arr);
    for (int x : res)
        cout << x << " ";
}