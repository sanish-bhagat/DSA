#include<bits/stdc++.h>
using namespace std;

//! TC is O(n * n!)
//! SC is O(n!)

void generatePermutations(int i, string &s, vector<bool> &used, unordered_set<string> &st, string &curr) {

    //base case
    if(i == s.size()) {
        st.insert(curr);
        return;
    }

    for(int j =  0; j<s.size(); j++) {

        if(!used[j]) {

            //mark the char
            used[j] = true;
            curr.push_back(s[j]);

            //recursive call
            generatePermutations(i + 1, s, used, st, curr);

            //back-track
            used[j] = false;
            curr.pop_back();
        }
    }
}

vector<string> findPermutation(string s) {

    //to track all char
    vector<bool> used(s.size(), false);

    //to get all unique permutations
    unordered_set<string> st;
    string curr = "";

    generatePermutations(0, s, used, st, curr);

    vector<string> res(st.begin(), st.end());
    return res;
}

int main() {
    string s = "ABC";
    vector<string> res = findPermutation(s);

    // Print the permutations
    for (string perm: res)
        cout << perm << " ";

    return 0;
}
