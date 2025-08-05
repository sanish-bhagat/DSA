#include <bits/stdc++.h>
using namespace std;

// TC is O(N*N)
// SC is O(1)

// use case : when size of array/vector is very small

void selectionSort(vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[minIndex])
            {
                minIndex = j;
            }
        }
        swap(v[minIndex], v[i]);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> vec(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    selectionSort(vec);

    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
}