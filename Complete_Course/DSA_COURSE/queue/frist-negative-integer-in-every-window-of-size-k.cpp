#include <iostream>
#include <queue>
using namespace std;

vector<int> printFirstNegativeInteger(int arr[], int n, int k)
{

    deque<int> dq;
    vector<int> ans;

    // process first window of k size

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i); // store indexes of negative element
        }
    }

    // store ans of first k sized window
    if (dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // process for remaining windows
    for (int i = k; i < n; i++)
    {

        // removal
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        // additon
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }

        // ans store
        if (dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
    int n = 5;
    int arr[n] = {-8, 2, 3, -6, 10};
    int k = 2;

    vector<int> ans = printFirstNegativeInteger(arr, n, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}