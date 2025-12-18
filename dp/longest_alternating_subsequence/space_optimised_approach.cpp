#include <bits/stdc++.h>
using namespace std;

int LAS(int arr[], int n)
{
    // every element is a LAS of length 1
    int inc = 1, dec = 1;

    //? we have to find a sequence of => up -> down -> up -> down (i.e alternative), can start with either

    // iterate through every element
    for (int i = 1; i < n; i++)
    {
        // arr[i] is greater -> current difference is positive,
        // therefore to maintain alteration the previous difference must be -ve
        // therefore we assign inc with dec + 1 as dec already stores the best sequence ending with a down
        if (arr[i] < arr[i - 1])
            inc = dec + 1;

        // arr[i] is smaller -> current difference is negative,
        // therefore to maintain alteration the previous difference must be +ve
        // therefore we assign dec with inc + 1 as inc already stores the best sequence ending with an up
        else if (arr[i] > arr[i - 1])
            dec = inc + 1;
    }

    // return the las
    return max(inc, dec);
}

int main()
{
    int arr[] = {10, 22, 9, 33, 49, 50, 31, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    cout << LAS(arr, n) << endl;
    return 0;
}