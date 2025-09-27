#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//! Approach 1 =>

//! TC is O(n*n log n)
//! SC is O(n * n)
// int getKthLargest(vector<int> &arr, int k) {
//     vector<int> sumStore;
//     int n = arr.size();

//     for(int i =0; i<n; i++) {
//         int sum = 0;
//         for(int j = i; j< n; j++) {
//             sum += arr[j];
//             sumStore.push_back(sum);
//         }
//     }

//     sort(sumStore.begin(), sumStore.end());

//     return sumStore[sumStore.size() - k];
// }

//! TC is O(n * n)
//! SC is O(k)
int getKthLargest(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();

    for(int i = 0; i<n; i++) {
        int sum = 0;
        for(int j = i; j<n; j++) {
            sum += arr[j];

            if(pq.size() < k) {
                pq.push(sum);
            }
            else {
                if(sum > pq.top()) {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}

int main() {
    vector<int> arr = {1,2,3,4,5};

    cout << getKthLargest(arr, 3);
}