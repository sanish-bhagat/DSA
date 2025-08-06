#include<bits/stdc++.h>
using namespace std;

//Tc is O((sum - maxi + 1) * N)

int findDays(vector<int> &v,int cap) {
    int days = 1,load = 0;

    for(int i=0; i<v.size(); i++) {
        if(load + v[i] > cap) {
            days = days + 1;
            load = v[i];
        } else {
            load += v[i];
        }
    }
    return days;
}

int minimumDays(vector<int> &v,int days) {
    int maxi = *max_element(v.begin(),v.end());
    int sum = accumulate(v.begin(),v.end(),0);
    
    for(int i=maxi; i<=sum; i++) {
        int daysReq = findDays(v,i);

        if(daysReq <= days) {
            return daysReq;
        }
    }
}

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    int days = 5;

    cout << minimumDays(v,days);
}