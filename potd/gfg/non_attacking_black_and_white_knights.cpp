#include <iostream>
using namespace std;

//! TC is O(1)
//! SC is O(1)

int numOfWays(int n, int m)
{
    // Total arrangements
    int ans = (n * m - 1) * n * m;

    if (n >= 1 && m >= 2) {
        
        // Attacks possible in one horizontal
        // and two vertical steps
        ans -= (4 * (n - 1) * (m - 2));
    }
    
    if (n >= 2 && m >= 1) {
        
        // Attacks possible in Two horizontal
        // and one vertical steps
        ans -= (4 * (n - 2) * (m - 1));
    }

    return ans;
}

int main()
{
    int n = 2, m = 3;
    cout << numOfWays(n, m) << endl;
    return 0;
}