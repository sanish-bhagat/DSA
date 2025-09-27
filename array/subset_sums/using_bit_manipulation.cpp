#include<bits/stdc++.h>
using namespace std;


vector<int> subsetSums(vector<int> arr)
{
    vector<int> res;
    int n = arr.size();

    for(int mask = 0; mask < (1 << n); mask++) {    //1 << n == 2 ^ n

        int sum = 0;

        for(int i = 0; i<n; i++) {

            if(mask & (1 << i))     //check if the ith element is part of the curr subset or not
                sum += arr[i];
        }

        res.push_back(sum);
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