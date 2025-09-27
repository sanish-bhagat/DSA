#include <iostream>
#include <vector>
using namespace std;

//! TC is O(n * k)
//! SC is O(1)

vector<int> maxOfSubarrays(vector<int> arr, int k)
{
    vector<int> res;
    int n = arr.size();

    for (int i = 0; i <= n - k; i++)
    {
        int maxi = arr[i];

        for (int j = 1; j < k; j++)
        {
            if (arr[i + j] > maxi)
                maxi = arr[i + j];
        }

        res.push_back(maxi);
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    vector<int> res = maxOfSubarrays(arr, k);
    for (int maxVal : res)
    {
        cout << maxVal << " ";
    }
    return 0;
}