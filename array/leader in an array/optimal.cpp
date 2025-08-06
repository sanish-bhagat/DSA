#include<bits/stdc++.h>
using namespace std;

//TC is O(N)
//SC is O(1) as no extra space is used but used an extra space to store the ans so the worst case SC is O(N)

void display(vector<int> &v) {
    for(int i=0;i<v.size();i++) {
        cout << v[i] << " ";
    }
}

void leader(vector<int> &a) {
    int maxi = INT_MIN;
    int n = a.size();

    vector<int> ans;

    for(int i = n-1;i>=0;i--) {
        if(a[i] > maxi) {
            ans.push_back(a[i]);
        }

        //keep track of right max

        maxi = max(maxi,a[i]);
    }

    //if mentioned in the question to sort
    //TC is O(N*logN)

    sort(ans.begin(),ans.end());
    display(ans);
}

int main() {
    int n,element;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> arr;
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++) {
        cin >> element;
        arr.push_back(element);
    }

    leader(arr);
}