#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    
    //use always unordered_map in place of map
    //but if using unordered_map gives TLE use map
    //in unordered_map you can only use one data-type
    //whereas in map all data-strutures can be used

    map<char,int> mpp;
    for(int i=0;i<s.size();i++) {
        mpp[s[i]]++;
    }

    int q;
    cout<<"Enter the no. of queries: ";
    cin>>q;

    while(q--) {
        char c;
        cin>>c;
        cout<<mpp[c]<<endl;
    }
}