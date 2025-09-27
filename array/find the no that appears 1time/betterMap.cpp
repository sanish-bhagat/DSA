#include<bits/stdc++.h>
using namespace std;

//size of the map is i.e M = (N/2 + 1)
//time complexity is O( N*logM ) + O(N/2 + 1) 
//space complexity is O(N/2 + 1)

int numberOnce(int arr[],int n) {
    map<long long,int> mpp;

    for(int i=0;i<n;i++) {
        mpp[arr[i]]++;
    }

    for(auto it: mpp) {
        if(it.second == 1) {
            return it.first;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    cout << numberOnce(arr,n);
}