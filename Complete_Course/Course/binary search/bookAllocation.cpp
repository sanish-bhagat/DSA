#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[],int n,int m,int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0;i<n;i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else {
            studentCount++;
            if(studentCount > m || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(int arr[],int n,int m) {
    int s = 0;
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += arr[i];
    }

    int e = sum;
    int mid = s + (e - s)/2;
    int ans = -1;

    while( s <= e) {
        if(isPossible(arr,n,m,mid)) {
            ans = mid;
            e = mid - 1;    //find the minimum value so go to left part of the array i.e, e = mid - 1
        } else {
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the no. of books: ";
    cin >> n;

    int arr[n];
    cout << "Enter the book page no.: ";
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int m;
    cout << "Enter the no. of students: ";
    cin >> m;

    cout << allocateBooks(arr,n,m);
}