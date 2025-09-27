#include<bits/stdc++.h>
using namespace std;

//! TC is O(2 ^ n)
//! SC is O(1)

vector<int> subsetSums(vector<int> arr)
{
    vector<int> res = {0};

    for(int num : arr) {

        int size = res.size();
        
        for(int i = 0; i<size; i++) {

            res.push_back(res[i] + num);
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {5, 4, 3};
    vector<int> result = subsetSums(arr);

    cout << "Subset Sums: ";
    for (int sum : result)
    {
        cout << sum << " ";
    }

    return 0;
}