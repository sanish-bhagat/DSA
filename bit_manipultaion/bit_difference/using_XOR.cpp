#include<bits/stdc++.h>
using namespace std;

// count the no. of set bits in 'n' 
int countSetBits(int n) {
    int count = 0;

    while(n > 0) {
        count++;
        n &= (n - 1);
    }

    return count;
}

//! TC is O(k)
//! SC is O(1)

int FlippedCount(int a, int b) {
    // finding the no. of set bits in the res of(a ^ b) ->
    // gives the total no. of bits which have to flipped to convert a -> b
    return countSetBits(a ^ b);
}

int main()
{
    int a = 10;
    int b = 20;
  
      // Function call
    cout << FlippedCount(a, b) << endl;
    return 0;
}