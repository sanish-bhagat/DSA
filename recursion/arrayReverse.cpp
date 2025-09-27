#include<bits/stdc++.h>
using namespace std;
void reverse(int arr[],int i,int j) {
    if(i>=j) return;

    swap(arr[i],arr[j]);
    reverse(arr,i+1,j-1);
    
}
int main() {
    int n=5;
    int arr[5]={1,2,3,4,5};
    reverse(arr,0,n-1);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}