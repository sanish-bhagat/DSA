#include <bits/stdc++.h>
using namespace std;

//! **for previous small element just change the flow the for loop

// TC is O(N)

vector<int> nextSmaller(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.top() >= curr)
        {
            s.pop();
        }

        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> v = {2, 1, 4, 3};

    vector<int> res = nextSmaller(v, 4);

    for (int i = 0; i < 4; i++)
    {
        cout << res[i] << " ";
    }
}