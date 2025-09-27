#include <bits/stdc++.h>
using namespace std;

//TC is O( n1 + n2)
//SC is O(n1 + n2)

double median(vector<int> v1, vector<int> v2)
{
    int n1 = v1.size(), n2 = v2.size(), n = n1 + n2;
    vector<int> v3;
    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (v1[i] < v2[j])
            v3.push_back(v1[i++]);
        else
            v3.push_back(v2[j++]);
    }
    while (i < n1)
        v3.push_back(v1[i++]);
    while (j < n2)
        v3.push_back(v2[j++]);

    if (n % 2 == 1)
    {
        return v3[n / 2];
    }

    return (double)((double)(v3[n / 2]) + (double)(v3[n / 2 - 1])) / 2.0;
}

int main()
{
    vector<int> v1 = {1, 3, 4, 7, 10, 12}, v2 = {2, 3, 6, 15};

    cout << median(v1, v2);
}