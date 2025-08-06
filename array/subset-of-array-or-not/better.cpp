#include<bits/stdc++.h>
using namespace std;

//! TC is O(m * log m + n * log n) 
//! SC is O(1)

bool isSubset(vector<int> &a, vector<int> &b) {

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;

    while(i < a.size() && j < b.size()) {

        if(a[i] < b[j])
            i++;        

        else if(a[i] == b[j])
            i++, j++;       //element present h

        else    
            return false;     //element present nhi h
    }

    return (j == b.size());     //agar sab elements of b[] traverse ho chuka h iska mtlb b[] subste h a[] ka
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