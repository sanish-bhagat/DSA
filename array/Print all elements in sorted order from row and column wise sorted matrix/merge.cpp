#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &arr1, vector<int> &arr2) {

    int i = 0, j = 0;
    vector<int> res;

    while(i < arr1.size() && j < arr2.size()) {

        if(arr1[i] < arr2[j]) 
            res.push_back(arr1[i++]);

        else    
            res.push_back(arr2[j++]);
    }

    while(i < arr1.size()) res.push_back(arr1[i++]);

    while(j < arr2.size()) res.push_back(arr2[j++]);

    return res;
}

vector<vector<int>> printSorted(vector<vector<int>> &mat) {

    int n = mat.size();

    vector<vector<int>> res(n, vector<int>(n));

    vector<int> temp = mat[0];

    for(int i = 1; i<n; i++) {
        temp = merge(temp, mat[i]);
    }

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