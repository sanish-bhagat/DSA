#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

bool isProduct(vector<int> &arr, long long target)
{
    // keep track of seen elements during traversal
    unordered_set<int> st;

    for (int num : arr)
    {
        // If target is 0 and current number is 0, return true.
        if (target == 0 && num == 0)
            return true;

        // target is divisible by curr num
        if (num != 0 && target % num == 0)
        {
            long long curr = target / num;

            // If the secondNum has been seen before -> pair found
            if (st.count(curr))
            {
                // pair is of distinct elements -> return true
                if (curr != num)
                    return true;
            }
        }

        // mark the curr num as seen
        st.insert(num);
    }

    // no valid pair
    return false;
}

int main()
{
    vector<int> arr = {10, 20, 9, 40};
    long long target = 400;

    if (isProduct(arr, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}