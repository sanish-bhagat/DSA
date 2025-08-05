#include<bits/stdc++.h>
using namespace std;

// time complexity is O(N)

int secondLargest(int arr[],int n) {

    int largest=arr[0];
    int slargest=INT_MIN;

    for(int i=1;i<n;i++) {

        if(arr[i] > largest) {

            slargest=largest;
            largest=arr[i];

        } else if(arr[i] < largest && arr[i] > slargest) {

            slargest=arr[i];

        }
    }

    return slargest;
}

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements opf the array: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    
    cout<<secondLargest(arr,n);
}