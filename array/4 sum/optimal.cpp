#include <bits/stdc++.h>
using namespace std;

// TC is O(N^3)
// SC is O(no. of quards)

vector<vector<int>> fourSum(vector<int> &v, int target)
{
    int n = v.size();
    vector<vector<int>> ans;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    { // O(N)
        if (i > 0 && v[i] == v[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        { // O(N)
            if (j != i + 1 && v[j] == v[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;

            while (k < l)
            { // O(N)
                long long sum = v[i];
                sum += v[j];
                sum += v[k];
                sum += v[l];

                if (sum > target)
                {
                    l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                {
                    vector<int> temp = {v[i], v[j], v[k], v[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while (k < l && v[k] == v[k - 1])
                        k++;
                    while (k < l && v[l] == v[l + 1])
                        l--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }

    int target;
    cout << "Enter the sum of the quards: ";
    cin >> target;

    vector<vector<int>> res = fourSum(v, target);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}