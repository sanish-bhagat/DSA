#include<bits/stdc++.h>
using namespace std;

//TC is O(N)
//SC is O(1)

pair<int,int> missingAndRepeating(vector<int> &v,int n) {
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0;

    for(int i=0; i<n; i++) {
        S += v[i];
        S2 += (long long)v[i] * (long long)v[i];
    }

    long long val1 = S - SN;  // x - y
    long long val2 = S2 - S2N;

    val2 = val2/val1;  // x + y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x,(int)y};
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

    cout << res.first << " " << res.second;
}