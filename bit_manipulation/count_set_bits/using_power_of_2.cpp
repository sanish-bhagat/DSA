#include<bits/stdc++.h>
using namespace std;

int findK(int n) {
    int k;
    int i=0;

    int val = pow(2, i);

    while(val <= n) {
        k = i;
        i++;

        val = pow(2, i);
    }

    return k;
}

//! TC is O(logn)
//! SC is O(1)

int countSetBits(int n) {
    // find the max value of k such that pow(2, k) <= n
    int k = findK(n);

    int count = 0;
    int val, x;

    // count the power of 2's present in n,
    // since power of 2 is represented by 1, so this helps in counting the no. of set bits
    for(int i=k; i>=0; i--) {
        val = pow(2, i);

        x = n & val;

        if(x > 0)
            count++;
    }

    return count;
}

int main()
{
    int N = 9;
    
    // Function call
    cout << countSetBits(N) << endl;
    return 0;
}