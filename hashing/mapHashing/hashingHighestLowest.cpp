#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    map<int,int> mpp;
    for(int i=0;i<n;i++) {
        mpp[arr[i]]++;
    }

    int q;
    cout<<"Enter the no. of queries: ";
    cin>>q;

    while(q--) {
        int num;
        cin>>num;
        mpp[num];
        int max=0;
        for(int i=0;i<n;i++) {
            if(max<mpp[num]) {
                max=num;
                max++;
                break;
            }
        }
        cout<<max;
    }
}