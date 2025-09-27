#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int getMaxArea(vector<int> &arr)
{
    int n = arr.size();
    int maxArea = 0;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        //if any smaller element is found
        while (!st.empty() && arr[i] <= arr[st.top()])
        {
            int element = st.top();
            st.pop();

            //the current bar is next smaller bar for the popped element i.e, for arr[element]
            int nse = i;

            //after popping the new top is the prev smaller bar
            int pse = st.empty() ? -1 : st.top();

            //calculate the width and area for the popped element
            int width = nse - pse - 1;
            int area = arr[element] * width;

            //update the maxArea
            maxArea = max(maxArea, area);
        }

        //push the curr index
        st.push(i);
    }

    //compute area for the left out elements of the stack, keeping nse = n
    while (!st.empty())
    {
        int element = st.top();
        st.pop();

        int nse = n;
        int pse = st.empty() ? -1 : st.top();

        int width = nse - pse - 1;
        int area = arr[element] * width;

        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main()
{
    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};
    cout << getMaxArea(arr) << endl;
    return 0;
}