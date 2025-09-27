#include <iostream>
#include <vector>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

vector<int> nextLargerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                res[i] = arr[j];
                break;
            }
        }
    }
    return res;
}

int main()
{

    vector<int> arr = {6, 8, 0, 1, 3};

    vector<int> res = nextLargerElement(arr);
    for (int x : res)
    {
        cout << x << " ";
    }

    return 0;
}