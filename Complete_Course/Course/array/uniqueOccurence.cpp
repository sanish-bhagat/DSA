#include<iostream>
using namespace std;

int uniqueArray(int arr[],int n) {
    int ans=0;
    int count=0;

    for(int i=0;i<n;i++) {
        if(ans^=arr[i]) {
            count++;
        } 
    }
    return count;
}

int main() {
    int arr[6]={1,2,5,2,1};

    cout<<uniqueArray(arr,6);
}