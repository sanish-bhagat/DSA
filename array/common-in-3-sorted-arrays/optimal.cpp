#include <bits/stdc++.h>
using namespace std;

//! TC is O(n1 + n2 + n3)
//! SC is O(1)

vector<int> common(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int n1 = a.size(), n2 = b.size(), n3 = c.size();

    vector<int> res;

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2 && k < n3)
    {
        if (a[i] == b[j] && b[j] == c[k])
        {
            res.push_back(a[i]);
            i++, j++, k++;

            // duplicate elements check krro
            while (i < n1 && a[i] == a[i - 1])
                i++;

            while (j < n2 && b[j] == b[j - 1])
                j++;

            while (k < n3 && c[k] == c[k - 1])
                k++;
        }

        else if (a[i] < b[j])
        {
            i++; // a[] i smaller
        }

        else if (b[j] < c[k])
            j++; // b[] is smaller

        else
            k++; // c[] is smaller
    }

    return res;
}

int main()
{
    vector<int> A = {1, 5, 10, 20, 30};
    vector<int> B = {5, 13, 15, 20};
    vector<int> C = {5, 20};

    vector<int> ans = common(A, B, C);

    cout << "Common elements: ";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}