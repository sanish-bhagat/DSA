// A fraud detection system wants to find:

// “How many continuous sequences of transactions sum to exactly K?”

#include<bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int noOfSequence(vector<int> &transactions, int k) {

    // subarray sum -> no. of occurence
    unordered_map<int, int> mp;

    // 1 subarray has sum == 0
    mp[0] = 1;

    int cnt = 0;

    int sum = 0;

    // traverse through the transactions
    for(int x: transactions) {

        // include the curr element in the running sum
        sum += x;
        
        // sum - k present in hashmap -> the curr subarray sums up to sum -> includes its count
        if(mp.find(sum - k) != mp.end())
            cnt += mp[sum - k];

        // include the curr running sum in hashmap
        mp[sum]++;
    }

    return cnt;
}

int main() {
    vector<int> transactions = {1, 2, 3, -2, 5};
    int k = 5;

    cout << noOfSequence(transactions, k);
}