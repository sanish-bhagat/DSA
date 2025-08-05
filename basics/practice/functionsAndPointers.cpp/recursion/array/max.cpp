#include<iostream>
using namespace std;

int main() {
    int arr[5]={10,25,45,65,8};
    int max=arr[0];
    for(int i=0;i<=4;i++) {
        if(max>arr[i]) {
            max=arr[i];
        }
    }
    cout<<max;
}