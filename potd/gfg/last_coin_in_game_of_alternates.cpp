#include <bits/stdc++.h>
using namespace std;

int coin(vector<int> &arr)
{
    int mini = INT_MAX;

    int i = 0, j = arr.size() - 1;

    // keep track of the min coin, which will remain till last
    while (i <= j)
    {
        mini = min({mini, arr[i++], arr[j--]});
    }

    return mini;
}

int main()
{
    vector<int> arr = {11, 22, 44, 22, 11};
    cout << coin(arr);
}