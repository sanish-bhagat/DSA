#include <bits/stdc++.h>
using namespace std;

// TC is O(N*N*N) + log(N*unique elements)
// SC is 2 * O(no of triplets)

vector<vector<int>> triplet(vector<int> &v)
{

    set<vector<int>> st;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            for (int k = j + 1; k < v.size(); k++)
            {
                if (v[i] + v[j] + v[k] == 0)
                {

                    // store the unique element =>

                    vector<int> temp = {v[i], v[j], v[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
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

    cout << "Enter the elements: ";

    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> ans = triplet(v);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}