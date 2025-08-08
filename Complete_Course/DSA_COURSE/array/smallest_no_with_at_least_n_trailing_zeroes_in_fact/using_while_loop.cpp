#include <iostream>
using namespace std;

//! TC is O(n * log n)
//! SC is O(1)

int findNum(int n)
{
    int num = 1, cnt = 0;

    while (true)
    {
        int temp = num;

        while (temp % 5 == 0)
        {
            cnt++;
            temp /= 5;
        }

        if (cnt >= n)
            return num;

        num++;
    }
}

int main()
{
    int n = 6;
    cout << findNum(n) << endl;
    return 0;
}