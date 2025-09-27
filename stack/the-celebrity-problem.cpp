#include <bits/stdc++.h>
using namespace std;

//TC is O(N)

bool knows(vector<vector<int>> arr, int a, int b, int n) {
    if(arr[a][b] == 1)
        return true;
    else
        return false;
}

int celebrity(vector<vector<int>> &arr, int n) 
{
    stack<int> s;

    // step1: push all elements in stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // step2: get 2 elements and compare them
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(arr, a, b, n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    int ans = s.top();

    // step3: single element in stack is potenital celeb
    // so verify it

    // bool rowCheck = false;
    int zeroCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[ans][i] == 0)
        {
            zeroCount++;
        }
    }

    // all zeroes
    // if (zeroCount == n)
    //     rowCheck = true;

    if(zeroCount != n)
        return -1;

    // column check
    // bool colCheck = false;
    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i][ans] == 1)
            oneCount++;
    }

    // if (oneCount == n - 1)
    //     colCheck = true;
    if(oneCount != n-1)
        return -1;

    // if (rowCheck == true && colCheck == true)
    //     return ans;
    // else
    //     return -1;

    return ans;
}

int main()
{
    vector<vector<int>> v = {{0,1,0},
    {0,0,0},
    {0,1,0}};

    cout << celebrity(v, 3);
}