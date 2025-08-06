#include <bits/stdc++.h>
using namespace std;

// TC is O(N*N*N)

void noOfSubarray(vector<int> &arr, int num)
{
    int n = arr.size();

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;

            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            if (sum == num)
            {
                count++;
            }
        }
    }

    cout << "The no of subarray with sum " << num << " is " << count;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr;
    int element;

    cout << "Enter the elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> element;
        arr.push_back(element);
    }

    int num;
    cout << "Enter the sum of the subarray: ";
    cin >> num;

    noOfSubarray(arr, num);
}