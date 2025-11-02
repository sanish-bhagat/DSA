#include <bits/stdc++.h>
using namespace std;

// find the gcd of the capacities
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int pour(int fromCap, int toCap, int d)
{
    // initially fill from jug
    int from = fromCap;
    int to = 0;

    // one step for filling 'from'
    int steps = 1;

    while (from != d && to != d)
    {
        // max amount that can be poured
        int temp = min(from, toCap - to);

        // pour temp amount
        to += temp;
        from -= temp;
        steps++;

        // reached the goal
        if (from == d || to == d)
            break;

        // 'from' becomes empty, fill it
        if (from == 0)
        {
            from = fromCap;
            steps++;
        }

        // 'to' becomes full, empty it
        if (to == toCap)
        {
            to = 0;
            steps++;
        }
    }

    return steps;
}

//! TC is O(d)
//! SC is O(1)

int minSteps(int m, int n, int d)
{
    // goal is greater than the max capacity of jugs -> solution not possible
    if (d > max(m, n))
        return -1;

    // d is not a multiple of gcd(m, n) -> solution not possible
    if (d % gcd(m, n) != 0)
        return -1;

    // try both ways: pour m -> n and pour n -> m
    return min(pour(m, n, d), pour(n, m, d));
}

int main()
{

    // jug1 = 4 litre, jug2 = 3 litre
    int m = 4, n = 3, d = 2;
    cout << minSteps(m, n, d);
    return 0;
}