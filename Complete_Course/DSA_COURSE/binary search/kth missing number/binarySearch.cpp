#include <bits/stdc++.h>
using namespace std;

//TC is O(N)

int missingNumber(vector<int> &v, int k)
{
    int low = 0,high = v.size() - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        int missing = v[mid] - (mid + 1);

        if(missing < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high + 1 + k;   //oe return low + k  (low = high + 1)
}

int main()
{
    vector<int> v = {2, 3, 4, 7, 11};

    int k = 5;

    cout << missingNumber(v, k);
}