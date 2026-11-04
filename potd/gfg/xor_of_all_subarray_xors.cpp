#include <iostream>
#include <vector>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int subarrayXor(vector<int> &arr)
{
    int result = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        // Check if (i+1) and (n-i) are both odd
        if ((i + 1) % 2 != 0 && (n - i) % 2 != 0)
        {
            // Include element in final XOR
            result ^= arr[i];
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 2, 4};
    cout << subarrayXor(arr) << endl;
    return 0;
}