#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! Sc is O(1)

void threeWayPartition(int arr[], int n, int lowVal, int highVal)
{

    // two pointers array ka start and end mein intialise krrdo
    int start = 0, end = n - 1;

    for (int i = 0; i <= end;)
    {

        // check for the lower value
        if (arr[i] < lowVal)
        {

            // agar i == start tab swap krr k koi faayda nhi h
            if (i == start)
            {
                i++, start++;
            }

            // agar dono pointers equal nhi h tab swap krrdo
            else
            {
                swap(arr[i++], arr[start++]);
            }
        }

        // agar arr[] element highVal se bada ho tab swap krrdo
        else if (arr[i] > highVal)
        {
            swap(arr[i], arr[end--]);
        }

        else
        {
            i++;
        }
    }
}

int main()
{
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int n = sizeof(arr) / sizeof(arr[0]);

    threeWayPartition(arr, n, 10, 20);

    cout << "Modified array \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}