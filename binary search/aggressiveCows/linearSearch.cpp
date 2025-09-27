#include <bits/stdc++.h>
using namespace std;

//Tc is O

bool canWePlace(vector<int> v, int distance, int cows)
{
    int cntCows = 1, last = v[0];

    for (int i = 0; i < v.size(); i++)
    {
        if ((v[i] - last) >= distance)
        {
            cntCows++;
            last = v[i];
        }

        if (cntCows >= cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> v, int cows)
{
    sort(v.begin(), v.end());

    int maxi = *max_element(v.begin(), v.end());
    int mini = *min_element(v.begin(), v.end());

    for (int i = 1; i <= maxi - mini; i++)
    {
        if (canWePlace(v, i, cows) == true)
        {
            continue;
        }
        else
        {
            return (i - 1);
        }
    }
}

int main()
{
    vector<int> v = {0, 3, 4, 7, 9, 10};

    int cows = 4;

    cout << aggressiveCows(v, cows);
}