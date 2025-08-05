#include <bits/stdc++.h>
using namespace std;

//!TC is O(n * m)
//! SC is O(n * m)

void spiralMatrix(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    while (top <= bottom && left <= right)
    {

        for (int i = left; i <= right; i++)
        {
            cout << arr[top][i] << " ";
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][right] << " ";
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << arr[bottom][i] << " ";
            }
            bottom--;
        }

        if (left < +right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;
}

int main()
{
    int n, m;

    cout << "Enter the rows: ";
    cin >> n;

    cout << "Enter the columns : ";
    cin >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cin >> arr[i][j];
        }
    }

    spiralMatrix(arr);
}