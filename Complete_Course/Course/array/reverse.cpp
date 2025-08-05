#include <iostream>
using namespace std;

void reverse(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        // int temp=arr[start];
        // arr[start]=arr[end];
        // arr[end]=temp;

        swap(arr[start], arr[end]);

        start++;
        end--;
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};

    reverse(arr, 6);
    print(arr, 6);
}