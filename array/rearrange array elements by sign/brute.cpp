#include<bits/stdc++.h>
using namespace std;

//TC is O(N) + O(N/2)
//SC is O(N)

void display(vector<int> &v) {
    for(int i=0;i<v.size();i++) {
        cout << v[i] << " ";
    }
}

vector<int> rearrangeArray(vector<int> &v) {
    int n = v.size();

    vector<int> pos,neg;

    for(int i=0;i<n;i++) {
        if(v[i] > 0) {
            pos.push_back(v[i]);
        }
        else {
            neg.push_back(v[i]);
        }
    }

    for(int i=0;i<n;i++) {
        v[2*i] = pos[i];
        v[2*i+1] = neg[i];
    }
    display(v);
}

int main() {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> arr;
    int element;
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++) {
        cin >> element;
        arr.push_back(element);
    }   

    rearrangeArray(arr);
}