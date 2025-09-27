#include <bits/stdc++.h>
using namespace std;

// TC is O(N * M)
//SC is O(M) (no. of col)

const int MAX = 100;

vector<int> nextSmallestElement(int arr[], int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallestElement(int arr[], int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(int heights[], int n)
{
    vector<int> next(n);
    next = nextSmallestElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallestElement(heights, n);

    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        int newArea = l * b;

        area = max(area, newArea);
    }

    return area;
}

int maxArea(int arr[MAX][MAX], int n, int m) {

    //compute area for first row
    int area = largestRectangleArea(arr[0], m);

    for(int i=1; i<n ;i++) {
        for(int j=0; j<m; j++) {

            //row update: by adding previous row's value
            if(arr[i][j] != 0)
                arr[i][j] = arr[i][j] + arr[i-1][j];

            else 
                arr[i][j] = 0;
        }

        //entire row is updated row
        area = max(area, largestRectangleArea(arr[i], m));
    }
    return area;
}

int main()
{
    int arr[MAX][MAX] = {{0,1,1,0},
    {1,1,1,1},
    {1,1,1,1},
    {1,1,0,0}};

    cout << maxArea(arr, 4, 4);
    
}