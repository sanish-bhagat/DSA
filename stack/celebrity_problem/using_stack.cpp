#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int celebrity(vector<vector<int>> &mat)
{
    int n = mat.size();
    stack<int> st;

    //push all the indexes no. in the stack
    for (int i = 0; i < n; i++)
        st.push(i);

    //jb tak stack ka size 2 ya usse jyada ho
    while (st.size() > 1)
    {
        //pop out first index
        int a = st.top();
        st.pop();

        //pop out second index
        int b = st.top();
        st.pop();

        //if a knows b than push b again as it can be a celebrity
        if (mat[a][b])
            st.push(b);
        else   
            st.push(a);
    }

    //re-check for the celebrity
    int c = st.top();
    st.pop();

    for (int i = 0; i < n; i++)
    {
        //for diagonal elements
        if (i == c)
            continue;

        //check in the row and the column of the potential celebrity
        if (mat[c][i] || !mat[i][c])
            return -1;
    }

    return c;
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 0},
                               {0, 0, 0},
                               {0, 1, 0}};
    cout << celebrity(mat);
    return 0;
}