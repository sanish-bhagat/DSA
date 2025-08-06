#include<bits/stdc++.h>
using namespace std;

//TC is O(N) * O(log N)    {log N depends upon the type of map used}
//SC is O(N) at the worst case

int countSubarray(vector<int> &v,int target) {
    int xr = 0;
    map<int,int> mpp;   //O(log N)
    mpp[xr]++;   //(0,1)
    int count = 0;

    for(int i=0;i<v.size();i++) {
        xr ^= v[i];
        int x = xr ^ target;
        count += mpp[x];
        mpp[xr]++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements: ";
    for(int i=0;i<v.size();i++) {
        cin >> v[i];
    }

    int target;
    cout << "Enter the XOR of the subarray: ";
    cin >> target;

    cout << countSubarray(v,target);
}