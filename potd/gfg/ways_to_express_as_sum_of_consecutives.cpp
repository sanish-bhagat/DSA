#include <bits/stdc++.h>
using namespace std;

//! TC is O(sqrt n)
//! SC is O(1)

//? if nothing comes in mind, use two ptrs, some test cases may pass, TC is O(n), SC is O(1)

int getCount(int n)
{
    int cnt = 0;

    // Example: n = 15

    // For k = 2: baseSum = 1. Check (15 - 1) % 2. Since 14 is divisible by 2, it's valid (count = 1)
    // For k = 3: baseSum = 3. Check (15 - 3) % 3. Since 12 is divisible by 3, it's valid (count = 2)
    // For k = 4: baseSum = 6. Check (15 - 6) % 4. Since 9 is NOT divisible by 4, it fails. (count remains 2)
    // For k = 5: baseSum = 10. Check (15 - 10) % 5. Since 5 is divisible by 5, it's valid (count = 3)
    // For k = 6: baseSum = 15. Because baseSum is now greater than or equal to 15, break the loop

    // k is the number of consecutive elements.
    // We start from k = 2.
    // The condition k * (k - 1) < 2 * n ensures the starting element 'a' > 0

    for (long long k = 2; k * (k - 1) < 2LL * n; k++)
    {
        // Check if 2n is divisible by k
        if ((2LL * n) % k == 0)
        {
            long long val = (2LL * n) / k - k + 1;

            // Check if 'a' will be a valid integer
            if (val > 0 && val % 2 == 0)
                cnt++;
        }
    }

    return cnt;
}

int main()
{
    int n = 15;
    cout << getCount(n);
}