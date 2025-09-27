#include<bits/stdc++.h>
using namespace std;

int findSqrt(int n) {
    int low = 1, high = n, ans = 1;

    while(low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;

        if(val <= n) {
            ans = mid;
            low = mid + 1;   //as we have to get the max nearest element
        } else {
            high = mid - 1;
        }
    }
    return high;  //either return high or ans
}

int main() {
    int n;
    cout << "Enter the element: ";
    cin >> n;

    cout << findSqrt(n);
}