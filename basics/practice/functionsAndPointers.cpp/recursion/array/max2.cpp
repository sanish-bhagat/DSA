#include<iostream>
#include<climits>
using namespace std;

int main() {
    int arr[7]={1,2,3,7,8,6,7};
    int max=INT_MIN;
    int smax=INT_MIN;
    for(int i=0;i<7;i++) {
        if(max<arr[i]) {
            smax=max;
            max=arr[i];
        } else if(smax<arr[i] && max!=arr[i]) {
            smax=arr[i];
        }
    }
    cout<<max<<" ";
    cout<<smax;
}