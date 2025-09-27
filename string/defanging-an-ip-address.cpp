#include<bits/stdc++.h>
using namespace std;

//Tc is O(n)   n = s.size()
//SC is O(n)

string defang(string s) {
    string ans;
    int index = 0;

    while(index < s.size()) {
        if(s[index] == '.') {
            ans += "[.]";
        } else {
            ans += s[index];
        }
        index++;
    }
    return ans;
}

int main() {
    string s = "1.1.1.1";

    cout << defang(s);    
}