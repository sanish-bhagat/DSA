#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[],int n,int arr2[],int m) {
    int i = 0;
    int j = 0;

    while(i<n) {
        if(arr1[i] < arr2[j]) {
            i++;
        }else {
            swap(arr1[i],arr2[j]);
            i++;
        }

        while(i>=3 && i<n) {
        if(arr1[i] == 0) {
            swap(arr1[i],arr2[j]);
            i++,j++;
        }
    }
}

    
}

int main() {
    int n = 6,m = 3;
    int arr1[n] = {1,3,4,0,0,0};
    int arr2[m] = {2,5,6};

    merge(arr1,n,arr2,m);
    for(int i=0;i<n;i++) {
        cout << arr1[i] << " ";
    }
}