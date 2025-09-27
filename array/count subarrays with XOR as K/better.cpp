#include<bits/stdc++.h>
using namespace std;

//TC is O(N*N)
//SC is O(1)

int countSubarray(vector<int> &v,int target) {
    int n = v.size();
    int count = 0;
    for(int i=0;i<n;i++) {
        int XOR = 0;

        for(int j=i;j<n;j++) {
            XOR ^= v[j];
            if(XOR == target) count++;
        }
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
    cout << "Enter the XOR of the target: ";
    cin >> target;

    cout << countSubarray(v,target);
}