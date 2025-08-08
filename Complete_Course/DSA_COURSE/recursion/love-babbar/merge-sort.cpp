#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low,int high) {

    int mid = (low + high) / 2;

    int len1 = mid - low + 1;
    int len2 = high - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = low;

    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;

    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = low;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }
}

void mergeSort(vector<int> &arr,int low, int high) {

    //base case
    if(low >= high) return;

    int mid = (low + high) / 2;

    //left part sort krr do
    mergeSort(arr,low,mid);

    //right part sort krr do
    mergeSort(arr,mid + 1, high);

    merge(arr,low, high);

}

int main() {
    vector<int> arr = {3,5,1,2,0};

    mergeSort(arr,0,arr.size() - 1);

    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
}