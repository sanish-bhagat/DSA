#include <bits/stdc++.h>
using namespace std;

// leader means that everything on the right should be smaller

// TC is O(N*N)
// SC is O(1) as no extra space is used but used an extra space to store the ans so the worst case SC is O(N)

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

void leader(vector<int> &arr)
{
    int n = arr.size();

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        bool leader = true;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                leader = false;
                break;
            }
        }

        if (leader == true)
            ans.push_back(arr[i]);
    }
    display(ans);
}

int main()
{
    int n, element;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> arr;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        arr.push_back(element);
    }

    leader(arr);
}