#include<bits/stdc++.h>
using namespace std;

//Tc is O(r)
//SC is O(1)

int ncr(int n,int r) {
    int res = 1;

    for(int i=0;i<r;i++) {
        res *= n - i;
        res /= i + 1;
    }

    return res;
}

int main() {
    int n,r;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter r: ";
    cin >> r;

    cout << ncr(n-1,r-1);
}