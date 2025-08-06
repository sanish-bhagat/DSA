#include <bits/stdc++.h>
using namespace std;

// timecomplexity is O(n) + O(N) = O(2N)
// space complexity is O(1)

void sortArray(int arr[], int n)
{
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    for (int i = 0; i < count0; i++)
        arr[i] = 0;
    for (int i = count0; i < count0 + count1; i++)
        arr[i] = 1;
    for (int i = count0 + count1; i < n; i++)
        arr[i] = 2;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sortArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}