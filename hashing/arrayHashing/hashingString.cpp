#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout<<"Enter the string: ";
    cin>>s;

    int hash[256]={0};
    for(int i=0;i<s.size();i++) {
        hash[s[i]]++;
    }

    int q;
    cout<<"Enter the no. of queries: ";
    cin>>q;

    while(q--) {
        char c;
        cin>>c;
        cout<<hash[c]<<endl;
    }
}