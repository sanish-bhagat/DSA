#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * log(max))
//! SC is O(1)

bool isValid(vector<int> &woods, int k, int mid)
{

    int cnt = 0;

    for (int i = 0; i < woods.size(); i++)
    {
        cnt += woods[i] / mid;  //check krro kitne pieces of len 'mid' can be made
    }

    return cnt >= k;
}

int findMaxLen(vector<int> &woods, int k)
{
    int low = 1, high = *max_element(woods.begin(), woods.end());

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (isValid(woods, k, mid))
            low = mid + 1;
        else
            high = mid - 1;
    }

    return high;
}

int main()
{
    vector<int> wood = {5, 9, 7};
    int K = 4;
    cout << findMaxLen(wood, K);
}