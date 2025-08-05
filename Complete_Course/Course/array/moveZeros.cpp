#include<bits/stdc++.h>
using namespace std;

void moveZeros(int arr[],int n) {
    int nonZero = 0;

    for(int i=0;i<n;i++) {
        if(arr[i] != 0) {
            swap(arr[i],arr[nonZero]);
            nonZero++;
        }
    }
}

int main() {
    int n = 6;
    int arr[n] = {0,3,2,0,0,1};

    moveZeros(arr,n);

    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
}