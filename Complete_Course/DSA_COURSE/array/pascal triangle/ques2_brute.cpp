#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
    int f = 1;

    for(int i=1;i<n;i++) {
        f *= i;
    }
    return f;
}

int ncr(int n,int r) {
    int ans = (fact(n)/(fact(r)*fact(n-r)));
    return ans;
}

void nthRow(int n,int c) {
    for(int i=1;i<=n;i++) {
        cout << ncr(n-1,c-1);
    }
}

int main() {
    int n,r;
    cout << "Enter n: ";
    cin >> n;

    //cout << "Enter r: ";
    //cin >> r;

    nthRow(n,r);
}