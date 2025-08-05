#include<iostream>
using namespace std;

bool linearSearch(int arr[],int n,int key) {

    //base case
    if(n == 0) return false;

    if(arr[0] == key) return true;

    else {
        linearSearch(arr+1,n-1,key);
    }
}

int main() {
    int arr[5] = {3,5,1,2,6};
    int key = 2;

    if(linearSearch(arr,5,key)) {
        cout <<"Present";
    } else {
        cout << "Not present";
    }
}