#include<iostream>
using namespace std;

int main() {
    int arr[5]={1,25,45,65,8};
    int min=arr[0];
    for(int i=0;i<=4;i++) {
        if(min>arr[i]) {
            min=arr[i];
        }
    }
    cout<<min;
}