#include <bits/stdc++.h>
using namespace std;

//TC is O(N)

int missingNumber(vector<int> &v, int k)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] <= k)
            k++;
        else
            break;
    }
    return k;
}

int main()
{
    vector<int> v = {2, 3, 4, 7, 11};

    int k = 5;

    cout << missingNumber(v, k);
}