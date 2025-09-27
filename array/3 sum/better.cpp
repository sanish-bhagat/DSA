#include <bits/stdc++.h>
using namespace std;

// TC is O(N*N) + O(log (size of set))
// SC is O(N) + O(2*(no. of unique elements))

vector<vector<int>> triplet(vector<int> &v)
{
    set<vector<int>> st;

    for (int i = 0; i < v.size(); i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < v.size(); j++)
        {
            int third = -(v[i] + v[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {v[i], v[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(v[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> v(n);

    cout << "Enter the elements : ";

    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> res = triplet(v);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}