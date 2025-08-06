#include<bits/stdc++.h>
using namespace std;

//! TC is O(n + m)
//! SC is (n)

bool isSubset(vector<int> &a, vector<int> &b) {
    unordered_map<int, int> freq;

    for(int i = 0; i<a.size(); i++) {
        freq[a[i]]++;
    }

    for(int i = 0; i<b.size(); i++) {
        if(freq[b[i]] > 0)
            freq[b[i]]--;

        else   
            return false;
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