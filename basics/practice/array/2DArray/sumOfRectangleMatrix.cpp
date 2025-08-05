#include<iostream>
using namespace std;

int main() {
    int arr[3][4];
    for(int i=0;i<3;i++) {
        for(int j=0;j<4;j++) {
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<3;i++) {
        for(int j=0;j<4;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int l1=0;
    int r1=1;
    int l2=2;
    int r2=4;

    int sum=0;
    for(int i=l1;i<=l2;i++) {
        for(int j=r1;j<=r2;j++) {
            sum+=arr[i][j];
        }
    }
    cout<<"The sum of the matrix is: "<<sum;
}