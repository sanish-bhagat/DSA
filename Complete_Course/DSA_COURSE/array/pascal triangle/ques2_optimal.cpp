#include<bits/stdc++.h>
using namespace std;

//TC is O(n)
//SC is O(1)

void nthRow(int n) {
    int ans = 1;
    cout << ans << " ";

    for(int i=1;i<n;i++) {
        ans *= n - i;
        ans /= i;
        cout << ans << " ";
    }
}

int main() {
    int n,r;

    cout << "Enter n: ";
    cin >> n;

    //cout << "Enter r: ";
    //cin >> r;
    nthRow(n);
}