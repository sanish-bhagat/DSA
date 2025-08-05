#include<bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> &v) {
    int s = 0;
    int e = v.size()-1;

    while(s<=e) {
        swap(v[s],v[e]);
        s++,e--;
    }
    return v;
}

vector<int> sum(vector<int> &v1,vector<int> &v2) {
    int i = v1.size()-1,j = v2.size()-1, carry = 0;
    
    vector<int> ans;

    while(i>=0 && j>=0) {
        int sum = v1[i] + v2[j] + carry;
        carry = sum/10;
        int value = sum%10;
        ans.push_back(value);
        i--;
        j--;
    }

    while(i>=0) {   // if first array's size is large
        int sum = v1[i] + carry;
        carry = sum/10;
        int value = sum%10;
        ans.push_back(value);
        i--;
    }

    while(j>=0) {   // if second array's size is large
        int sum = v2[j] + carry;
        carry = sum/10;
        int value = sum%10;
        ans.push_back(value);
        j--;
    }

    while(carry != 0) {   // for third case i.e if any carry is present
        int sum = carry;
        carry = sum/10;
        int value = sum%10;
        ans.push_back(value);
    }

    return reverse(ans);
}

int main() {
    vector<int> v1 = {2,4,6};
    vector<int> v2 = {2,4};

    vector<int> ans = sum(v1,v2);

    for(int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
}