#include<bits/stdc++.h>
using namespace std;

//TC is O(N^3)
//SC is O(1)

int countSubaaray(vector<int> &v,int target) {
    int n = v.size();

    int count = 0;

    for(int i=0;i<n;i++) {

        for(int j=i;j<n;j++) {
            int XOR = 0;

            for(int k=i;k<=j;k++) {
                XOR ^= v[k];
            }

            if(XOR == target) count ++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";

    for(int i=0;i<arr.size();i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the XOR of the subarray: ";
    cin >> target;

    cout << countSubaaray(arr,target);
}