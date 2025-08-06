#include <iostream>
#include <vector>
#include <set>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

vector<int> findLeastGreater(vector<int> arr, int n)
{
    set<int> bst;
    vector<int> res(n);

    for (int i = n - 1; i >= 0; i--)
    {
        // find the first greater element
        auto it = bst.upper_bound(arr[i]);

        // element exists then only push the element in the res, else push -1
        if (it != bst.end())
            res[i] = *it;

        else
            res[i] = -1;

        // insert arr element into the set
        bst.insert(arr[i]);
    }

    return res;
}

int main()
{
    vector<int> arr = {2, 6, 9, 1, 3, 2};
    vector<int> result = findLeastGreater(arr, arr.size());

    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}