#include<bits/stdc++.h>
using namespace std;

//Tc is O(N*N)
//SC is O(1)

int countReversePairs(vector<int> &v,int n) {
    int cnt = 0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(v[i] > 2 * v[j]) cnt++;
        }
    }

    return cnt;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++)     {
        cin >> arr[i];
    }

    cout << countReversePairs(arr,n);
}