#include <bits/stdc++.h>
using namespace std;

// TC is O( n1 + n2)

double median(vector<int> v1, vector<int> v2)
{
    int n1 = v1.size(), n2 = v2.size(), n = n1 + n2;
    int i = 0, j = 0;
    int ind2 = n / 2, ind1 = ind2 - 1;
    int ind1el = -1, ind2el = -1;
    int cnt = 0;

    while (i < n1 && j < n2)
    {
        if (v1[i] < v2[j])
        {
            if (cnt == ind1)
                ind1el = v1[i];
            if (cnt == ind2)
                ind2el = v1[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                ind1el = v2[j];
            if (cnt == ind2)
                ind2el = v2[j];
            cnt++;
            j++;
        }
    }
    while (i < n1)
    {
        if (cnt == ind1)
            ind1el = v1[i];
        if (cnt == ind2)
            ind2el = v1[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            ind1el = v2[j];
        if (cnt == ind2)
            ind2el = v2[j];
        cnt++;
        j++;
    }

    if (n % 2 == 1)
    {
        return ind2el;
    }
    return (double)(double)(ind1el + ind2el) / 2.0;
}

int main()
{
    vector<int> v1 = {1, 3, 4, 7, 10, 12}, v2 = {2, 3, 6, 15};

    cout << median(v1, v2);
}