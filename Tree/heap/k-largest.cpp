#include <iostream>
#include <queue>
using namespace std;

//! To find the smallest element we use max heap and
//! To find the largest element we use min heap

//! TC is O(N)
//! SC is O(k)
int kThLargest(int arr[], int n, int k)
{
    // int n = nums.size();
  // priority_queue<int, vector<int>, greater<int>> pq;

  // for (int i = 0; i < k; i++) {
  //   pq.push(nums[i]);
  // }

  // for (int i = k; i < n; i++) {
  //   if (nums[i] > pq.top()) {
  //     pq.pop();
  //     pq.push(nums[i]);
  //   }
  // }
  // return pq.top();

  priority_queue<int, vector<int>, greater<int>> pq;

  for(int i = 0; i<n; i++) {
    pq.push(arr[i]);
    if(pq.size() > k)
      pq.pop();
  }

  return pq.top();
}

int main()
{
    int arr[5] = {7, 10, 4, 20, 15};

    cout << kThLargest(arr, 5, 4);

}