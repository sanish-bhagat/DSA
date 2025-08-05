#include<iostream>
using namespace std;

int main() {
    int arr[6]={1,5,7,2,10,9};
    int sumEven=0;
    int sumOdd=0;
    for(int i=0;i<=5;i++) {
        if(i%2==0) {
            sumEven+=arr[i];
        } else {
            sumOdd+=arr[i];
        }
    }
    cout<<"The difference is: "<<sumEven-sumOdd;
}