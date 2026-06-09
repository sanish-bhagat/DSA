#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

bool canSeatAllPeople(int k, vector<int> &seats)
{
    int n = seats.size();

    for (int i = 0; i < n; i++)
    {
        // check the left and right neighbor
        bool left = (i == 0) || seats[i - 1] == 0;
        bool right = (i == n - 1) || seats[i + 1] == 0;

        // place the people in the curr positon
        if (seats[i] == 0 && left && right)
        {
            seats[i] = 1;
            k--;

            // all k people have been placed
            if (k <= 0)
                return true;
        }
    }

    return k <= 0;
}

int main()
{
    int k = 2;
    vector<int> seats = {0, 0, 1, 0, 0, 0, 1};

    cout << canSeatAllPeople(k, seats);
}