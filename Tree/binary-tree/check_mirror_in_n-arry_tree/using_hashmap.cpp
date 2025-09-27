#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

//! TC is O(e)
//! SC is O(n + e)

int checkMirror(int n, int e, int A[], int B[])
{
    unordered_map<int, stack<int>> mpp;

    // map the original tree's connected nodes
    for (int i = 0; i < e; i++)
    {
        mpp[A[2 * i]].push(A[2 * i + 1]);
    }

    // check in the B[] in reverse order
    for (int i = 0; i < e; i++)
    {
        if (mpp[B[2 * i]].top() != B[2 * i + 1])
            return 0;

        mpp[B[2 * i]].pop();
    }

    return 1;
}

int main()
{
    int n = 3, e = 2;
    int A[] = {1, 2, 1, 3};
    int B[] = {1, 3, 1, 2};

    if (checkMirror(n, e, A, B))
        cout << "1";
    else
        cout << "0";

    return 0;
}