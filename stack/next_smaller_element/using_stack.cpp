#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

vector<int> findNextSmallerElement(vector<int> &arr)
{
    vector<int> res(arr.size(), -1);

    // to store the indices
    stack<int> st;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            res[st.top()] = arr[i];
            st.pop();
        }

        // push the curr index into stack
        st.push(i);
    }

    return res;
}

int main()
{
    // Input array
    vector<int> arr = {4, 8, 2, 1, 6, 10, 5};

    // Function call to find next smaller elements
    vector<int> result = findNextSmallerElement(arr);

    // Print the original array
    cout << "Original Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    // Print the next smaller elements
    cout << "Next Smaller Elements: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}