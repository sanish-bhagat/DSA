#include<bits/stdc++.h>
using namespace std;

//TC is O(N) + O(N/2)
//SC is O(N)
//opitmal solution if positive and negative elements are not given in equal no.

void display(vector<int> &v) {
    for(int i=0;i<v.size();i++) {
        cout << v[i] << " ";
    }
}

vector<int> rearrangeArray(vector<int>& a) {
    vector<int> pos,neg;
    int n = a.size();

    for(int i=0;i<n;i++) {
        if(a[i] > 0) {
            pos.push_back(a[i]);
        } else {
            neg.push_back(a[i]);
        }
    }

    if(pos.size() > neg.size()) {
        for(int i=0;i<neg.size();i++) {
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }

        int index = neg.size() * 2;
        for(int i= neg.size();i<pos.size();i++) {
            a[index] = pos[i];
            index++;
        }
    }

    else {
        for(int i=0;i<neg.size();i++) {
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int index = pos.size() * 2;
        for(int i= pos.size();i<neg.size();i++) {
            a[index] = neg[i];
            index++;
        }
    }

    display(a);
}

int main() {
    vector<int> arr;

    int element,size;

    cout << "Enter the size of the vector: ";
    cin >> size;

    cout << "Enter the elements: ";
    for(int i=0;i<size;i++) {
        cin >> element;
        arr.push_back(element);
    }

    rearrangeArray(arr);
}