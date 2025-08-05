#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//! TC is O(N)
int maxFreq(vector<int> &arr, int n)
{
    unordered_map<int, int> count;

    int maxFreq = 0;
    int maxAns = 0;

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for (int i = 0; i < n; i++)
    {
        if (maxFreq == count[arr[i]])
        {
            maxAns = arr[i];
            break;  // to get the first max occuring element (one with the lower index)
        }
    }
    return maxAns;
}

int main()
{
    vector<int> v = {1,2,1,3,2};
    cout << maxFreq(v, 5) << endl;
}