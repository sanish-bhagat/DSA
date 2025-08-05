#include<bits/stdc++.h>
using namespace std;

//! TC is O(n + m)
//! Sc is O(1)

int count(vector<vector<int>> &arr) {

    int n = arr.size(), m = arr[0].size();
    int row = 0, col = m - 1, maxCount = 0;

    while(row < n && col >= 0) {

        if(arr[row][col] == 0) 
            row++;

        else {
            maxCount = row;
            col--;
        }
    }

    return maxCount;
}

int main()
{
    vector<vector<int>> v = {
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1}};

    cout << count(v);
}