#include<bits/stdc++.h>
using namespace std;

//time complexity is O(N*N)
//space complexity is O(1)

int numberOnce(int arr[],int n) {
    for(int i=0;i<n;i++) {
        int num = arr[i];
         int count = 0;

         for(int j=0;j<n;j++) {
            if(arr[j] == num) {
                count++;
            }
         }

         if(count == 1) return num;
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