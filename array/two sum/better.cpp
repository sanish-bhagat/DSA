#include <bits/stdc++.h>
using namespace std;

// time complexity is O(N* logN) for ordered map and for unordered map best case it is O(N) and for worst case it is O(N*N)
// space complexity is O(N)
// optimal solution if indexes are needed

void twoSum(int arr[], int n, int m)
{

    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        int more = m - arr[i];

        if (mpp.find(more) != mpp.end())
        {
            cout << mpp[more] << " " << i; // return {mpp[more],i}
        }
        mpp[arr[i]] == i;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m;
    cout << "Enter the sum : ";
    cin >> m;

    twoSum(arr, n, m);
}