#include<bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> arr) {
    
    //base case
    if(arr.size() == 0)
        return {};

    sort(arr.begin(), arr.end());
    
    stack<pair<int, int>> st;
    st.push(arr[0]);

    for(int i=1; i<arr.size(); i++) {
        auto top = st.top();

        if(top.second >= arr[i].first) {
            top.second = max(top.second, arr[i].second);
            st.pop();
            st.push(top);
        }
        else {
            st.push(arr[i]);
        }
    }

    vector<pair<int, int>> res;

    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    sort(res.begin(), res.end());
    return res;
}

int main() {
    vector<pair<int, int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<pair<int, int>> merged = mergeIntervals(intervals);

    for (auto& interval : merged) {
        cout << "[" << interval.first << ", " << interval.second << "] ";
    }

    return 0;
}
