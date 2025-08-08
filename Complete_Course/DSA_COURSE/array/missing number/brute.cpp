#include<bits/stdc++.h>
using namespace std;

//time complexity is O(N*N)
//space complxity is O(1)

 int missing(int arr[], int n) {
    for(int i =1;i<=n;i++) {
        bool flag = 0;
        for(int j = 0;j<n-1;j++) {
            if(arr[j] == i) {
                flag = 1;
                break;
            }
        }

        if(flag==0) return i;
    }
 }

int main() {
    int n;
    cout << "Emter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n-1 ; i++) {
        cin >> arr[i];
    }

    cout<<missing(arr,n);
}