#include<iostream>
using namespace std;

int intersection(int arr[],int arr1[],int n) {
    int i=0,j=0;
    int ans;

    while(i<n && j<n) {
        if(arr[i]==arr1[j]) {
            ans=arr[i];
            i++;
            j++;
            break;
        }
        else if(arr[i]<arr1[j]) {
            i++;
        } else {
            j++;
        }
    }
    return ans;
}

int main() {
    int arr[4]={1,0,3,4};
    int arr1[4]={2,3,4,5};

    cout<<intersection(arr,arr1,4);
}       