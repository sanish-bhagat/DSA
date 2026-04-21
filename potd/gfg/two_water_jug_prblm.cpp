#include <bits/stdc++.h>
using namespace std;

// gives the gcd of two no.s using recursion
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

// fromCap -> capacity of jug fromm which water is to be poured
// toCap -> capacity of jug to which water is to be poured
int solve(int fromCap, int toCap, int d)
{
    int from = fromCap, to = 0;

    // initial fill step
    int steps = 1;

    // process until any of the two jugs have exactly d litres of water hold into it
    while (from != d && to != d)
    {
        // min amount of water that can be poured
        int temp = min(from, toCap - to);

        // pour the water into the jug in this step
        to += temp;
        from -= temp;
        steps++;

        // break if any jug has d litres of water holding
        if (from == d || to == d)
            break;

        // refill the jug
        if (from == 0)
        {
            from = fromCap;
            steps++;
        }

        // empty the jug
        if (to == toCap)
        {
            to = 0;
            steps++;
        }
    }

    return steps;
}

//! TC is O(n)
//! SC is O(1)

int minSteps(int m, int n, int d)
{
    // make sure m is smaller than n
    if (m > n)
        swap(m, n);

    // impossible to measure d litres
    if (d > n)
        return -1;

    // solution not possible
    if (d % gcd(m, n) != 0)
        return -1;

    // find the min steps required
    return min(solve(m, n, d), solve(n, m, d));
}

int main()
{
    int n = 38, m = 99, d = 13;

    cout << minSteps(m, n, d);
}