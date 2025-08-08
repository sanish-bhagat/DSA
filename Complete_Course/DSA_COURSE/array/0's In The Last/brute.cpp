#include<bits/stdc++.h>
using namespace std;

//time complexity is O(n) + O(n-x) + O(x) => O(2n)
//extra space used is O(x)

void zero(vector<int> &arr,int n) {
    vector<int> temp;

    for(int i=0;i<n;i++) {
        if(arr[i] != 0) {
            temp.push_back(arr[i]);
        }
    }

    int nz=temp.size();

    for(int i=0;i<nz;i++) {
        arr[i]=temp[i];
    }

    for(int i=nz;i<n;i++) {
        arr[i]=0;
    }
    
}

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr;
    int element;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++) {
        cin>>element;
        arr.push_back(element);
    }

    zero(arr,n);
        
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }

}