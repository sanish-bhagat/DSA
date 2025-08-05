#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[],int n,int m,int mid) {
    int painterCount = 1;
    int sum = 0;

    for(int i=0;i<n;i++) {
        if(sum + arr[i] <= mid) {
            sum += arr[i];
        } else {
            painterCount++;
            if(painterCount > m || arr[i] > mid) {
                return false;
            }
            sum = arr[i];
        }
    }
    return true;
}

int painter(int arr[],int n,int m) {
    int s = 0;
    int sum = 0;

    for(int i=0;i<n;i++) {
        sum += arr[i];
    }

    int e = sum;
    int mid = s + (e - s)/2;
    int ans = -1;

    while(s <= e) {
        if(isPossible(arr,n,m,mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the no. of section to be painted: ";
    cin >> n;

    int arr[n];
    cout << "Enter the section: ";
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int m;
    cout << "Enter the no. of painter's: ";
    cin >> m;

    cout << painter(arr,n,m);
}