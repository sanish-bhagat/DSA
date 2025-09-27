#include<bits/stdc++.h>
using namespace std;

//TC is O(2N)
//SC is O(N)

pair<int,int> missingAndRepeating(vector<int> &v,int n) {
    int hash[n+1] = {0};  //SC => O(N)

    for(int i=0; i<n; i++) {
        hash[v[i]]++;   
    }

    int repeating = -1, missing = -1;

    for(int i=1; i<=n; i++) {
        if(hash[i] == 2) repeating = i;
        else if(hash[i] == 0) missing = i;

        if(repeating != -1 && missing != -1) break;
    }

    return {repeating,missing};
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    pair<int,int> res = missingAndRepeating(v,n);

    cout << res.first << " " << res.second ;
}