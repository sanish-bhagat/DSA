#include <bits/stdc++.h>
using namespace std;

// TC is O(3N)
// SC is O(1) i.e no extra space is used as we are modifying the given array but SC for the whole algorithm is O(N)

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

vector<int> nextPermutation(vector<int> &v)
{
    int idx = -1;
    int n = v.size();

    //Step 1 - Break point find krrlo
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] < v[i + 1])
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        reverse(v.begin(), v.end());
        display(v);
    }

    //Step 2 - arr[i] se sabse pass wala element find krrlo
    for (int i = n - 1; i > idx; i--)
    {
        if (v[i] > v[idx])
        {
            swap(v[i], v[idx]);
            break;
        }
    }

    //Step 3 - baaki bache hue elements ko sorted way mein arrange krrdo
    reverse(v.begin() + idx + 1, v.end());
    display(v);
}

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

    nextPermutation(arr);
}