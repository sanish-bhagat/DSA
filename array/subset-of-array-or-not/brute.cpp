#include<bits/stdc++.h>
using namespace std;

//! TTC is O(n * n)
//! SC is O(1)

bool isSubset(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();

    for(int i = 0; i<m; i++) {
        bool found = true;

        for(int j = 0; j<n; j++) {
            if(b[i] == a[j]) {
                found = true;
                break;
            }

            if(!found) return false;
        }
    }

    return true;
}

int main() {
    vector<int> a = {11, 1, 13, 21, 3, 7};
    vector<int> b = {11, 3, 7, 1};
  
    if (isSubset(a, b)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}