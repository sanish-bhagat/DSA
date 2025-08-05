#include<iostream>
using namespace std;

int main() {
    int arr[3][3]={1,2,3,4,20,6,7,8,9};
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int maxSum=0;
    int idx=-1;
    for(int i=0;i<3;i++) {
        int sum=0;
        for(int j=0;j<3;j++) {
            sum+=arr[i][j];
        }
        if(maxSum<sum) {
            maxSum=sum;
            idx=i;
        }
    }
    cout<<maxSum<<endl;
    cout<<idx;
}