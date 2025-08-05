#include <iostream>
using namespace std;

int duplicate(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cout << arr[i] << " ";
                break;
            }
        }
    }
}

int main()
{
    int arr[6] = {1, 1, 2, 2, 5, 7};

    duplicate(arr, 6);
}