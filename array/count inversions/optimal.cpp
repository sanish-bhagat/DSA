#include <bits/stdc++.h>
using namespace std;

// TC is O(N log N)
// SC is O(N)

int merge(vector<int> &v, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    int cnt = 0;
    while (left <= mid && right <= high)
    {
        if (v[left] <= v[right])
        {
            temp.push_back(v[left]);
            left++;
        }

        else
        {
            temp.push_back(v[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(v[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(v[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        v[i] = temp[i - low];
    }
    return cnt;
}

int mergeSort(vector<int> &v, int low, int high)
{
    int cnt = 0;
    
    if (low >= high)
        return cnt;

    int mid = (low + high) / 2;
    cnt += mergeSort(v, low, mid);
    cnt += mergeSort(v, mid + 1, high);
    cnt += merge(v, low, mid, high);

    return cnt;
}

int numberOfInversions(vector<int> &v, int n)
{
    return mergeSort(v, 0, n - 1);
}

int main()
{
    vector<int> arr= {4, 3, 2, 1};

    cout << numberOfInversions(arr, 4);
}