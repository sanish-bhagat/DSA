#include<iostream>
using namespace std;

int main() {
    int arr[10]={1,2,3,4,5,6,7,8,9,11};
    int sum=0;
    for(int i=0;i<10;i++) {
        sum+=arr[i];
    }
    int sum2=(11*(11+1))/2;
    cout<<sum2-sum;
}