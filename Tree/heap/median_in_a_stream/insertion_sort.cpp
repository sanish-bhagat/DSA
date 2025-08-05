#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

vector<double> getMedian(vector<int> &arr)
{
    vector<double> res;
    // push the first element as median, as only one element is in the stream
    res.push_back(arr[0]);

    // traverse the arr[]
    for (int i = 1; i < arr.size(); i++)
    {
        int j = i - 1;
        int num = arr[i];

        // shift all the greater elements to the right
        while (j >= 0 && arr[j] > num)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // insert the element at its correct position
        arr[j + 1] = num;

        // find the median and push it into the res[]
        double median;
        int len = i + 1;

        if (len % 2 != 0)
            median = arr[len / 2];

        else
            median = (double)(arr[(len / 2) - 1] + arr[len / 2]) / 2;

        res.push_back(median);
    }

    return res;
}

int main()
{
    vector<int> arr = {5, 15, 1, 3, 2, 8};
    vector<double> res = getMedian(arr);
    cout << fixed << setprecision(2);

    for (double median : res)
        cout << median << " ";
    return 0;
}