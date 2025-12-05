#include<bits/stdc++.h>
using namespace std;

int cutRodRec(int i, vector<int> &price, vector<int> &memo) {
    if(i == 0)
        return 0;

    if(memo[i] != -1)
        return memo[i];

    int ans = 0;
    for(int j=1; j<=i; j++)
        ans = max(ans, price[j - 1] + cutRodRec(i - j, price, memo));

    return memo[i] = ans;
}

int cutRod(vector<int> &price) {
    int n = price.size();

    vector<int> memo(n + 1, -1);

    return cutRodRec(n, price, memo);
}

int main() {
    vector<int> price =  { 1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price);
    return 0;
}