// binary search use krro jab tmhe pta ho ki ek part of the array ko neglect krrna h

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &v,int k,int mid) {
    int cowCount = 1;
    int lastPos = v[0];

    for(int i=0;i<v.size();i++) {
        if(v[i] - lastPos >= mid) {
            cowCount++;

            if(cowCount == k) {
                return true;
            }
            lastPos = v[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &v,int k)  {
    
    sort(v.begin(),v.end());

    int s = 0;
    int maxi = -1;

    for(int i=0;i<v.size();i++) {
        maxi = max(maxi,v[i]);
    }

    int e = maxi;
    int ans = -1;
    int mid = s + (e - s)/2;

    while(s <= e) {
        if(isPossible(v,k,mid)) {
            ans = mid;
            s = mid + 1;   // as we have to find the max value
        } else {
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> v(n);

    cout << "Enter the elements/stalls: ";
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }

    int k;
    cout << "Enter the no. of cows: ";
    cin >> k;

    cout << aggressiveCows(v,k);
}