#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

int defense(vector<int> &x, vector<int> &y)
{
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int maxX = 0, maxY = 0;

    // find the max gap b/w x-cordinates(gap - 1)
    for (int i = 1; i < x.size(); i++)
        maxX = max(maxX, x[i] - x[i - 1] - 1);

    // find the max gap b/w y-cordinates(gap - 1)
    for (int i = 1; i < y.size(); i++)
        maxY = max(maxY, y[i] - y[i - 1] - 1);

    // return the largest undefended rectangle
    return maxX * maxY;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int w, h, n;
        cin >> w >> h >> n;
        vector<int> x, y;
        x.push_back(0);
        x.push_back(w + 1);
        y.push_back(0);
        y.push_back(h + 1);

        for (int i = 0; i < n; i++)
        {
            int xi, yi;
            cin >> xi >> yi;
            x.push_back(xi);
            y.push_back(yi);
        }

        int res = defense(x, y);

        cout << "Result is: " << res << endl;
    }
}