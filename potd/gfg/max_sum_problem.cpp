#include <iostream>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int maxSum(int n)
{
    // base case
    if (n == 0 || n == 1)
        return n;

    // pick the max of the curr or recursive value
    int n1 = max(n / 2, maxSum(n / 2));
    int n2 = max(n / 3, maxSum(n / 3));
    int n3 = max(n / 4, maxSum(n / 4));

    // return the max value
    return max(n, n1 + n2 + n3);
}

int main()
{
    int n = 24;
    cout << maxSum(n);
}