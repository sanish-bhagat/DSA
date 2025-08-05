#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[],int n, int arr2[],int m,int arr3[]) {
    int i = 0,j = 0,k = 0;

    while(i<n && j<m) {
        if(arr1[i] < arr2[j]) {
            arr3[k] = arr1[i];
            k++,i++;
        } else {
            arr3[k] = arr2[j];
            k++,j++;
        }
    }

    while(i<n) {
        arr3[k] = arr1[i];
        k++,i++;
    }

    while(j<m) {
        arr3[k] = arr2[j];
        k++,j++;
    }
}

int main() {
    int n = 5,m = 3;
    int arr1[n] = {1,2,4,6,8};
    int arr2[m] = {3,5,7};

    int arr3[n + m] = {0};

    merge(arr1,n,arr2,m,arr3);

    for(int i=0;i<n+m;i++) {
        cout << arr3[i] << " ";
    }
}