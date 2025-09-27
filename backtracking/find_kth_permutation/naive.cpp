#include <bits/stdc++.h>
using namespace std;

void generate_permutations(string &str, int idx, vector<string> &res)
{
    // base case: permutation formed of the same size, store it and return
    if (idx == str.size())
    {
        res.push_back(str);
        return;
    }

    // traverse the element from idx to end
    for (int i = idx; i < str.size(); i++)
    {
        swap(str[i], str[idx]);
        generate_permutations(str, idx + 1, res);
        swap(str[i], str[idx]);
    }
}

//! TC is O((n! * n) + (n! * log n!))
//! SC is O(n)

string findKthPermutation(int n, int k)
{
    string str = "";

    vector<string> res;

    // insert all natural no. upto n in str
    for (int i = 1; i <= n; i++)
        str.push_back(i + '0');

    // generate all the permutations
    generate_permutations(str, 0, res);

    // sort the generated permutations
    sort(res.begin(), res.end());

    // return the kth permutation
    return res[k - 1];
}

int main()
{
    int n = 3, k = 4;

    // function call
    string kth_perm_seq = findKthPermutation(n, k);
    cout << kth_perm_seq << endl;

    return 0;
}