#include <bits/stdc++.h>
using namespace std;

//! TC is O(n) - its a two pass approach, so we have to modify it
//! SC is O(n)

vector<int> nextSmaller(vector<int> &arr)
{
    int n = arr.size();

    vector<int> nextS(n, n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            nextS[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return nextS;
}

vector<int> prevSmaller(vector<int> &arr)
{
    int n = arr.size();

    vector<int> prevS(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
            st.pop();

        if (!st.empty())
        {
            prevS[i] = st.top();
        }

        st.push(i);
    }

    return prevS;
}

int getMaxArea(vector<int> &arr)
{
    //will get the prev smaller element index 
    vector<int> prevS = prevSmaller(arr);

    //will get the next smaller element index 
    vector<int> nextS = nextSmaller(arr);

    int maxArea = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int width = nextS[i] - prevS[i] - 1;
        int area = arr[i] * width;

        maxArea = max(area, maxArea);
    }

    return maxArea;
}

int main()
{
    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};
    cout << getMaxArea(arr) << endl;
    return 0;
}