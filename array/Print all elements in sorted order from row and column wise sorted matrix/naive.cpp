#include<bits/stdc++.h>
using namespace std;

//! TC is O((n * n) * log (n * n))
//! SC is O(n * n)

vector<vector<int>> printSorted(vector<vector<int>> &mat) {

    int n = mat.size();

    vector<vector<int>> res(n, vector<int>(n));
    vector<int> temp;

    for(auto row : mat) {
        for(auto num : row) {

            temp.push_back(num);
        }
    }

    sort(temp.begin(), temp.end());

    int index = 0;

    for(int i = 0; i<n; i++) {
        
        for(int j = 0; j<n; j++) {

            res[i][j] = temp[index++];
        }
    }

    return res;
}

int main() {

    vector<vector<int>> matrix = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    vector<vector<int>> res = printSorted(matrix);

    for(auto row : res) {
        for(auto num : row) {

            cout << num << " ";
        }

        cout << endl;
    }
}