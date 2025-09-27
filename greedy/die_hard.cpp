#include <bits/stdc++.h>
using namespace std;

//! TC is O(h + a)
//! SC is O(1)

int die_hard(int h, int a)
{
    int time = 0;
    bool isAir = true;

    // choose between air, water and fire
    // simple observation is to go to air -> water -> air -> fire -> air -> water -> air....
    // as being in air increases both a and h, so we alternatively keep going to air and
    // we will choose between water and fire, we will go where we can survive
    while (true)
    {
        if (isAir)
        {
            h += 3;
            a += 2;
            time++;
            isAir = false;
        }

        else if (h - 5 > 0 && a - 10 > 0)
        {
            h -= 5;
            a -= 10;
            time++;
            isAir = true;
        }
        else if (h - 20 > 0 && a + 5 > 0)
        {
            h -= 20;
            a += 5;
            time++;
            isAir = true;
        }
        // no possible moves
        else
            break;
    }

    return time;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int h, a;
        cin >> h >> a;

        int res = die_hard(h, a);

        cout << "Result is: " << res << endl;
    }
}