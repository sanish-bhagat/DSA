#include<bits/stdc++.h>
using namespace std;

//! TC is O(2 ^ n)
//! SC is O(n)

int minimizeTime(int curr, int n, vector<int> &arr, int k) {

    //base case
    if(curr >= n)
        return 0;

    if(k == 0)
        return INT_MAX;

    int res = INT_MAX;
    int currSum = 0;

    for(int i = curr; i<n; i++) {
        currSum += arr[i];

        //recursive call
        int remTime = minimizeTime(i + 1, n, arr, k - 1);
        int remaining = max(currSum, remTime);

        res = min(res, remaining);
    }

    return res;
}

int minTime(vector<int> &arr, int k) {
    int n = arr.size();
    return minimizeTime(0, n, arr, k);
}

int main() {
    vector<int> arr = {10, 10, 10, 10};
    int k = 2;
    int res = minTime(arr, k);
    cout << res << endl;

    return 0;
}