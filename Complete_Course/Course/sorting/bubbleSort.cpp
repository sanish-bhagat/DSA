#include<bits/stdc++.h>
using namespace std;

//Tc is O(N*N)     for best case => O(N) and for worst case => O(N*N)
//sc is O(1)

void bubbleSort(vector<int> &v,int n) {

    for(int i=1;i<n;i++) {
        bool didSwap = false;

        for(int j=0;j<n-i;j++) {   // j(0 -> n-i)  as the last element of the array is already at its correct position
            if(v[j] > v[j+1]) {
                swap(v[j],v[j+1]);
                didSwap = true;
            }
        }
        if(didSwap == false) {   //check if the array is already sorted
            break;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> vec(n);
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++) {
        cin >> vec[i];
    }

    bubbleSort(vec,n);
    for(int i=0;i<n;i++) {
        cout << vec[i] <<" ";
    }
}