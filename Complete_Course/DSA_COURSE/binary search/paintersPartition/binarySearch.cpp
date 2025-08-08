#include <bits/stdc++.h>
using namespace std;

// TC is O(log(sum - max + 1)) * O(N)

int noOfPainters(vector<int> v, int maxLen)
{
    int cntPainters = 1, unitPainted = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (unitPainted + v[i] <= maxLen)
        {
            unitPainted += v[i];
        }
        else
        {
            cntPainters++;
            unitPainted = v[i];
        }
    }
    return cntPainters;
}

int paintersPartiton(vector<int> v, int painters)
{
    int low = *max_element(v.begin(), v.end());
    int high = accumulate(v.begin(), v.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int countPainters = noOfPainters(v, mid);

        if (countPainters > painters)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> v = {10, 20, 30, 40};

    int painters = 2;

    cout << paintersPartiton(v, painters);
}