#include<iostream>
using namespace std;
int uniqueArray(int arr[],int n) {
    int ans=0;

    for(int i=0;i<n;i++) {
        ans^=arr[i];
    }
    return ans;
}

int main() {
    int arr[6]={1,2,5,2,1};

    cout<<uniqueArray(arr,6);
}