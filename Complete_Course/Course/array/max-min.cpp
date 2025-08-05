#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int arr[5] = {12, 45, 25, 5, 90};

    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < 5; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }

        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    cout << max << " " << min;
}