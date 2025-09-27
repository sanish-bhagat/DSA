#include <bits/stdc++.h>
using namespace std;

// it's a in-built STL

int main()
{
    int element, n;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> arr;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        arr.push_back(element);
    }

    next_permutation(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}