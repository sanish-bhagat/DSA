#include<bits/stdc++.h>
using namespace std;

vector<int> findMin(int target) {
    // Indian currency coins/notes
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> res;

    //traverse the coins/notes
    for(int i=denominations.size() - 1; i>=0; i--) {
        // find the max coin/note which the target value needs to make the change
        while(target >= denominations[i]) {
            //keep updating the new target value
            target -= denominations[i];
            res.push_back(denominations[i]);
        }
    }

    // return the list of change coins of target value
    return res;
}

int main()
{
    int n = 43;
    vector<int> res = findMin(n);

    for(int n : res) {
        cout << n << " ";
    }
    return 0;
}