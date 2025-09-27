#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    int hash[13]={0};
    for(int i=0;i<n;i++) {
        hash[arr[i]]+=1;
    }

    int q;
    cout<<"Enter the no. of queries: ";
    cin>>q;

    while(q--) {
        int num;
        cin>>num;
        cout<<hash[num]<<endl;
    }
}