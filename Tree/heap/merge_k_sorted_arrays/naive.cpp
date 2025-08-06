#include<bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
    vector<int> res;

    for(auto const &val : arr) {
        for(int i : val)
            res.push_back(i);
    }

    sort(res.begin(), res.end());

    return res;
}

int main() {
    vector<vector<int>> arr = {{1, 3, 5, 7},
                              {2, 4, 6, 8}, 
                              {0, 9, 10, 11}};
                              
    int k = 3;
    vector<int> res = mergeKArrays(arr, k);

    // Print the array elements
    for (int val : res) {
        cout << val << " ";
    }

    return 0;
}