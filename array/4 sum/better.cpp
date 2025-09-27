#include <bits/stdc++.h>
using namespace std;

// TC is O(N^3) * O(Log(no. of elements in the set))
// Sc is O(N) + O(quards) * 2

vector<vector<int>> fourSum(vector<int> &v)
{
    set<vector<int>> st;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<int> hashset;
            for (int k = j + 1; k < n; k++)
            {
                int sum = v[i] + v[j];
                sum += v[k];

                int fourth = -sum;
                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {v[i], v[j], v[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(v[k]);
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