#include <bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int> &arr, int n, int k)
{
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }

    arr = temp;

    return arr;
}

int main()
{
    int n = 5;
    vector<int> arr = {1, 2, 3, 4, 5};

    int k = 2;

    vector<int> v = rotateArray(arr, n, k);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}