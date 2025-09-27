#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

vector<int> nextLargerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;

    //traverse from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        //agar curr element se smaller elements stack mein h toh pop krrdo
        while (!st.empty() && st.top() <= arr[i])
            st.pop();

        //agar pop krrne k baad bho stack mein elements h toh for curr element its the next greater element
        if (!st.empty())
            res[i] = st.top();

        //curr element ko stack mein push krrdo
        st.push(arr[i]);
    }

    return res;
}

int main()
{

    vector<int> arr = {6, 8, 0, 1, 3};

    vector<int> res = nextLargerElement(arr);
    for (int x : res)
    {
        cout << x << " ";
    }

    return 0;
}