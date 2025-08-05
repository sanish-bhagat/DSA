#include<bits/stdc++.h>
using namespace std;

//TC is O(N*N)

void noOfSubarray(int arr[],int n,int num) {
    int count = 0;

    for(int i=0;i<n;i++) {
        int sum = 0;

        for(int j=i;j<n;j++) {
            sum += arr[j];

            if(sum == num) {
            count++;
            }
        }
    }

    cout << "The no of subarray with sum "<<num<<" is "<<count;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int num;
    cout << "Enter the sum of the subarray: ";
    cin >> num;

    noOfSubarray(arr,n,num);
}