#include <bits/stdc++.h>
using namespace std;

//! TC is O(n+m)
//! SC is O(n)

//? Using two hash-set
vector<int> intersectionOfTwoArray(vector<int> &a, vector<int> &b)
{
    vector<int> res;

    unordered_set<int> as(a.begin(), a.end());
    unordered_set<int> rs;

    for (int i = 0; i < b.size(); i++)
    {
        if (as.find(b[i]) != as.end() && rs.find(b[i]) == rs.end())
        {
            res.push_back(b[i]);
            rs.insert(b[i]);
        }
    }

    return res;
}

//? Using one hash-set
// vector<int> intersectionOfTwoArray(vector<int> &a, vector<int> &b) {
//     vector<int> res;
//     unordered_set<int> as(a.begin(), a.end());

//     for(int i =0; i<b.size(); i++) {
//         if(as.find(b[i]) != as.end()) {
//             res.push_back(b[i]);
//             as.erase(b[i]);
//         }
//     }

//     return res;
// }

int main()
{
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> res = intersectionOfTwoArray(a, b);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}