#include<bits/stdc++.h>
using namespace std;

//TC is O(N * logN) ; logN => varies for different map type
//SC is O(N)

void noOfSubarray(vector<int> &arr,int num) {
    unordered_map<int,int> mpp;
    mpp[0] = 1;

    /*initialisation of preSum = 0 is important to get the correct value of count 
    if not initialised as 0 the count will be one less than the actual value of the count*/

    int preSum = 0,count = 0;

    for(int i=0;i<arr.size();i++) {
        preSum += arr[i];
        int remove = preSum - num;
        count += mpp[remove];
        mpp[preSum] += 1;
    }

    cout << "No. of subarray with sum " << num <<" is " << count << endl;
}

int main() {
    int n;
    cout <<"Enter the size of the array: ";
    cin >> n;

    vector<int> arr;
    int element;

    cout << "Enter the elements: ";
    for(int i=0;i<n;i++) {
        cin >> element;
        arr.push_back(element);
    }

    int num;
    cout << "Enter the sum of the subarray: ";
    cin >> num;

    noOfSubarray(arr,num);
}