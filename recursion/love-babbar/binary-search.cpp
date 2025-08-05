#include<iostream>
using namespace std;

bool binarySearch(int arr[],int s,int e,int key) {
    
    //base case
    if(s > e) return false;

    int mid = s + (e - s) / 2;

    if(arr[mid] == key) return true;

    if(arr[mid] < key) {
        return binarySearch(arr,mid + 1,e,key);
    } else {
        return binarySearch(arr,s,mid - 1,key);
    }
}

int main() {
    int arr[6] = {2,4,6,10,14,18};
    int key = 18;

    if(binarySearch(arr,0,5,key)) {
        cout << "Present";
    } else {
        cout << "Not present";
    }
}