#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(k)

int SumOfKsubArray(int arr[], int n, int k)
{
    int sum = 0;

    // In deque 'G' we maintain decreasing order of
    // values from front to rear
    // In deque 'S' we  maintain increasing order of
    // values from front to rear
    deque<int> S(k), G(k);

    int i = 0;
    for (i = 0; i < k; i++)
    {
        // remove all the previous greater elements from the deque
        while (!S.empty() && arr[S.back()] >= arr[i])
            S.pop_back();

        // remove all the previous smaller elements from the deque
        while (!G.empty() && arr[G.back()] <= arr[i])
            G.pop_back();

        // push the curr index into the deques
        S.push_back(i);
        G.push_back(i);
    }

    // process the remaining window
    for (; i < n; i++)
    {
        // element at the front are the min and max elements of the previous window respectively
        sum += arr[S.front()] + arr[G.front()];

        // if the front is out of the window remove it
        if (!S.empty() && S.front() == i - k)
            S.pop_front();

        if (!G.empty() && G.front() == i - k)
            G.pop_front();

        // remove the prev greater element
        while (!S.empty() && arr[S.back()] >= arr[i])
            S.pop_back();

        // remove the prev smaller element
        while (!G.empty() && arr[G.back()] <= arr[i])
            G.pop_back();

        // push the curr index
        G.push_back(i);
        S.push_back(i);
    }

    // add the max and min of the last window
    sum += arr[S.front()] + arr[G.front()];

    return sum;
}

int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int N = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout << SumOfKsubArray(arr, N, k);
    return 0;
}
