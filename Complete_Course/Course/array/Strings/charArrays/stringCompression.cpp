#include<bits/stdc++.h>
using namespace std;

//TC is O(N)
//SC is O(1)

int compress(vector<char> &s) {
    int i = 0;
    int ansIndex = 0;
    int n = s.size();

    while(i<n) {
        int j = i + 1;

        while(j<n && s[i] == s[j]) {
            j++;
        }

        //yaha kab aaoge =>
        //ya toh vector poora traverse krrliya
        //ya fer new/different character encounter kiya h

        //old character store kralo
        s[ansIndex] = s[i];

        int count = j - i;

        if(count > 1) {
            //convertig counting into single digit and saving in answer
            string cnt = to_string(count);

            for(char ch: cnt) {
                s[ansIndex++] = ch;
            }
        }
        i = j;
    }
    return ansIndex;
}

int main() {
    int n;
    cin >> n;
    vector<char> s(n);
    for(int i=0;i<s.size();i++) {
        cin >> s[i];
    }

    cout << compress(s);
}