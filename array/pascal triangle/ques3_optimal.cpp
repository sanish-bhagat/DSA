#include<bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);

    for(int i=1;i<row;i++) {
        ans = ans * (row - i);
        ans = ans / i;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    for(int i=1;i<=n;i++) {
    ans.push_back(generateRow(i));
    }
    return ans;
}

int main() {
    int n,r;

    cout << "Enter n: ";
    cin >> n;

    //cout << "Enter r: ";
    //cin >> r;

    vector<vector<int>> res = pascalTriangle(n);

    for(int i=0;i<res.size();i++) {
        for(int j=0;j<res[i].size();j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}