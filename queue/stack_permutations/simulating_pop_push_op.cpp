#include <bits/stdc++.h>
using namespace std;

//! TCT is O(n)
//! SC is O(1)

bool checkPerm(vector<int> &a, vector<int> &b)
{
    stack<int> st;
    //to keep track of elements of b[]
    int j = 0;

    //traverse the input array
    for (int i = 0; i < a.size(); i++)
    {
        //push the curr element into stack
        st.push(a[i]);

        //check if st.top mkacthes b[j] then pop both elements
        while (!st.empty() && st.top() == b[j])
        {
            st.pop();
            j++;
        }
    }

    //if the b array is fully traversed then its a permutation
    return (j == b.size());
}

int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> b = {2, 1, 3};

    cout << checkPerm(a, b);

    return 0;
}