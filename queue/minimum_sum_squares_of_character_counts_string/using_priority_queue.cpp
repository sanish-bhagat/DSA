#include <bits/stdc++.h>
using namespace std;

//! TC is O(k * logn)
//! SC is O(n)

int minStringValue(string &s, int k)
{
    vector<int> freq(26, 0);

    // compute the freq
    for (char ch : s)
        freq[ch - 'a']++;

    priority_queue<int> pq;

    // push the freq into the max heap
    for (int i : freq)
        pq.push(i);

    // decremenet the largest freq of the char
    while (k--)
    {
        int temp = pq.top();
        pq.pop();

        temp -= 1;
        pq.push(temp);
    }

    // calculate the res
    int res = 0;
    while (!pq.empty())
    {
        int temp = pq.top();
        pq.pop();
        res += temp * temp;
    }

    return res;
}

int main()
{
    string str = "abbccc"; // Input 1
    int k = 2;
    cout << minStringValue(str, k) << endl;

    str = "aaab"; // Input 2
    k = 2;
    cout << minStringValue(str, k);

    return 0;
}