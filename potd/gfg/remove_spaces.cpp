#include<bits/stdc++.h>
using namespace std;

// TC is O(n)
// SC is O(1)

string removeSpaces(string &s) {
    string res;

    // traverse through char of given string
    for(char c: s) {

       // skip white spaces
       if(c != ' ')
         res.push_back(c);
    }
  
    return res;
}

int main() {
    string s = "g  eeks   for ge  eeks  ";
    cout << removeSpaces(s);
    return 0;
}
