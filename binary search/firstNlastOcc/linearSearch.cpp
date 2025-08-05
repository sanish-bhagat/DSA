#include <bits/stdc++.h>
using namespace std;

// TC is O(N)

pair<int, int> linearSearch(int arr[], int n, int target)
{
    int first = -1, last = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            if (first == -1)
                first = i;
            last = i;
        }
    }

    return {first, last};
}

int main()
{
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to be searched: ";
    cin >> target;

    pair<int, int> res = linearSearch(arr, n, target);

    cout << res.first << "," << res.second << endl;
}