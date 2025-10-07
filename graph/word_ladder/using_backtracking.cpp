#include<bits/stdc++.h>
using namespace std;

int wordLadderRec(string start, string target, map<string, int> &mp) {
    if(start == target)
        return 1;

    mp[start] = 1;

    int mini = INT_MAX;

    for(int i=0; i<start.size(); i++) {
        char original = start[i];

        for(char ch = 'a'; ch<='z'; ch++) {
            start[i] = ch;

            if(mp.find(start) != mp.end() && mp[start] == 0) {
                mini = min(mini, 1 + wordLadderRec(start, target, mp));
            }
        }

        start[i] = original;
    }

    mp[start] = 0;

    return mini;
}

int wordLadder(string start, string target, vector<string> &arr) {
    map<string, int> mp;

    for(auto word: arr)
        mp[word] = 0;

    int res = wordLadderRec(start, target, mp);

    return (res == INT_MAX) ? 0 : res;
}

int main() {
    vector<string> arr = {"poon", "plee", "same", 
                          "poie", "plie", "poin", "plea"};
    string start = "toon";
    string target = "plea";

    cout << wordLadder(start, target, arr) << endl;

    return 0;
}