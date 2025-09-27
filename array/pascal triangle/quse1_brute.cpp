#include<bits/stdc++.h>
using namespace std;

//TC is O(n) + O(r) + O(n-r)

int fact(int n) {
    int f = 1;

    for(int i=1;i<=n;i++) {
        f *= i;
    }

    return f;
}

int ncr(int n,int r) {
    int ans = (fact(n) / (fact(r)*fact(n-r)));
    return ans;
}

int main() {
    int n,r;
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter r: ";
    cin >> r;

    cout << ncr(n-1,r-1);
}