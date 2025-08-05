#include<iostream>
using namespace std;

int main() {
    int arr[7]={1,2,3,4,5,6,7};
    int x=4;
    int idx=0;
    bool flag=false;
    for(int i=0;i<7;i++) {
        if(arr[i]==x) {
            flag=true;
            idx=i;
            break;
        } 
    }

    if(flag=true) {
        cout<<"The no. is present in the array and its index is "<<idx;
    } else {
        cout<<"The no. is not present";
    }
}