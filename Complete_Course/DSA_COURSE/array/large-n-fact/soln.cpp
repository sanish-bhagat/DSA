#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! Sc is O(1)  (as we have to return a vector)   else tell that it will be O(n)

vector<int> factorial(int n) {
    vector<int> result;
    result.push_back(1); // Initialize result as 1
    
    for (int x = 2; x <= n; x++) {
        int carry = 0;
        for (size_t i = 0; i < result.size(); i++) {
            int prod = result[i] * x + carry;
            result[i] = prod % 10; // Store the last digit
            carry = prod / 10; // Carry forward the remaining part
        }
        
        while (carry) { // Handle remaining carry digits
            result.push_back(carry % 10);
            carry /= 10;
        }
    }
    
    reverse(result.begin(), result.end()); // Reverse to match human-readable order
    return result;
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    
    vector<int> result = factorial(n);
    
    cout << "Factorial of " << n << " is: ";
    for (int digit : result) {
        cout << digit;
    }
    cout << endl;
    
    return 0;
}
