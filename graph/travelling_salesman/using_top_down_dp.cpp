#include<bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>> &cost) {
    
}

int main() {

    vector<vector<int>> cost = {{0, 10, 15, 20}, 
                                {10, 0, 35, 25}, 
                                {15, 35, 0, 30}, 
                                {20, 25, 30, 0}};

    int res = tsp(cost);
    cout << res << endl;

    return 0;
}