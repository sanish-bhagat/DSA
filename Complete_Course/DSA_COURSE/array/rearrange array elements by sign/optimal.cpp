#include<bits/stdc++.h>
using namespace std;

//TC is O(N)
//SC is O(N)
//opytimal solution only when there are equal no. of positive and negative elements

void display(vector<int> &v) {
    for(int i=0;i<v.size();i++) {
        cout << v[i]<< " ";
    }
}

void rearrangeElements(vector<int> &arr) {

    int posIndex = 0;
    int negIndex = 1;

    int n = arr.size();

    vector<int> ans(n,0);

    for(int i=0;i<n;i++) {
        if(arr[i] < 0) {
            ans[negIndex] = arr[i];
            negIndex += 2;
        } else {
            ans[posIndex] = arr[i];
            posIndex +=2;
        }
    }
    display(ans);
}

int main() {
    vector<int> arr;

    int element,size;
    cout << "Enter the size of the vector : ";
    cin >> size;

    cout << "Enter the elements : ";
    for(int i=0;i<size;i++) {
        cin >> element;
        arr.push_back(element);
    }   

    rearrangeElements(arr);
}