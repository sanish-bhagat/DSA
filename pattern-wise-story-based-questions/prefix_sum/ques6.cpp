// Story 4: Equal 0s, 1s, and 2s

// 👉 Find:

// Number of subarrays with equal count of 0, 1, and 2

#include<bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int equalCount(vector<int> &arr) {

    // store pairs in hashmap
    map<pair<int, int>, int> mp;

    // keep track of count of elements
    int c0=0, c1 = 0, c2 = 0;

    int cnt = 0;

    // base case
    mp[{0, 0}] = 1;

    // traverse through elements
    for(int x: arr) {

        // increment the count
        if(x == 0)  c0++;
        else if(x == 1) c1++;
        else    c2++;

        // count difference
        int d1 = c0 - c1;
        int d2 = c0 - c2;

        pair<int, int> key = {d1, d2};

        // include the count of the valid subarray
        if(mp.count(key))
            cnt += mp[key];

        // include the curr key in hashmap
        mp[key]++;
    }

    return cnt;
}

int main() {
    vector<int> arr = {0, 1, 0, 2, 0, 1, 0};
    cout << equalCount(arr);
}