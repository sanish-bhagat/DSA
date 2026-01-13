#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

bool canServe(vector<int> &arr)
{
    // counters for incoming and outgoing 5/- and 10/- coins
    int five = 0, ten = 0;

    for (int bill : arr)
    {
        // no exchange required -> fair is 5/-
        if (bill == 5)
            five++;

        // 5/- exchange is required
        else if (bill == 10)
        {
            // no 5/- coin left -> no exchange available
            if (five == 0)
                return false;

            // update the counters
            five--, ten++;
        }

        // bill is 20/- -> exchange required 15/-
        else
        {
            // 10 + 5 = 15/-
            if (ten > 0 && five > 0)
                ten--, five--;

            // 5 * 3 = 15
            else if (five >= 3)
                five -= 3;

            // no exchnage available
            else
                return false;
        }
    }

    return true;
}

int main()
{
    vector<int> arr = {5, 5, 5, 10, 20};
    cout << canServe(arr);
}