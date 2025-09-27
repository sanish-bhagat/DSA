#include<bits/stdc++.h>
using namespace std;

// time complexity is NlogN + N
//space complexity is O(N)

int isSorted(int arr[],int n) {
    set<int> st;
    for(int i=0;i<n;i++) {
        st.insert(arr[i]);
    }

    int index=0;

    for(auto it: st) {
        arr[index]=it;
        index++;
    }
    return index;
}

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<isSorted(arr,n);
    
}