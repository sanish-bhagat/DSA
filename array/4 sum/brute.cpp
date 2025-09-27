#include <bits/stdc++.h>
using namespace std;

// TC is O(n^4)
// SC is O(no. of quards) * 2

vector<vector<int>> fourSum(vector<int> &v)
{
    set<vector<int>> st;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    int sum = v[i] + v[j];
                    sum += v[k];
                    sum += v[l];

                    if (sum == 0)
                    {
                        vector<int> temp = {v[i], v[j], v[k], v[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
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

    vector<vector<int>> res = fourSum(v);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}