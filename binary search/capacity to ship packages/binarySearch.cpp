#include<bits/stdc++.h>
using namespace std;

//Tc is O(log (sum - max + 1) * N)

int findSum(vector<int> &v) {
    int sum =0;

    for(int i=0; i<v.size(); i++) {
        sum += v[i];
    }
    return sum;
}

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
    int low = *max_element(v.begin(),v.end());
    int high = accumulate(v.begin(),v.end(),0);

    while(low <= high) {
        int mid = (low + high) / 2;

        int noOfDays = findDays(v,mid);

        if(noOfDays <= days) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    int days = 5;

    cout << minimumDays(v,days);
}