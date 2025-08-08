#include <bits/stdc++.h>
using namespace std;

//! TC is O(e)
//! SC is O(e)

int checkMirror(int n, int e, int A[], int B[])
{
    // create vectors to store stacks and queues for each node
    vector<stack<int>> s;
    vector<queue<int>> q;

    // initialise the vectors with empty stack and queues
    for (int i = 0; i <= n; i++)
    {
        s.push_back(stack<int>());
        q.push_back(queue<int>());
    }

    // push the node values into stack and queue
    for (int i = 0; i < 2 * e; i += 2)
    {
        s[A[i]].push(A[i + 1]);
        q[B[i]].push(B[i + 1]);
    }

    // if node value ranges between 1 - n then loop 1 -> n
    // if node value ranges between 0 - n then loop 0 -> n
    for (int i = 1; i <= n; i++)
    {
        // compare the nodes of the two trees by popping out elements from stack and queue
        while (!s[i].empty() && !q[i].empty())
        {
            int a = s[i].top();
            s[i].pop();

            int b = q[i].front();
            q[i].pop();

            // if nodes don't match trees are not mirror
            if (a != b)
                return 0;
        }

        // if any node is left after comparison then return 0
        if (!s[i].empty() || !q[i].empty())
            return 0;
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