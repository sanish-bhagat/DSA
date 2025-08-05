#include <bits/stdc++.h>
using namespace std;

// TC is O(N*N)     for best case => O(N)  and  for worst case => O(N*N)
// SC is O(1)

// used because it is stable algorithm and adaptable

void insertionSort(vector<int> &v, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = v[i];
        int j = i - 1;

        for (; j >= 0; j--)
        {
            if (v[j] > temp)
            {
                v[j + 1] = v[j]; // shift krro element ko
            }
            else
            {
                break; // ruk jao
            }
        }
        v[j + 1] = temp;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> v(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    insertionSort(v, n);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}