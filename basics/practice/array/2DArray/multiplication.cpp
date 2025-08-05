#include<iostream>
using namespace std;

int main() {
    int m;
    cout<<"Enter the no of rows of 1st matrix: ";
    cin>>m;
    int n;
    cout<<"Enter the no of column of 1st matrix: ";
    cin>>n;

    int arr1[m][n];
    cout<<"Enter the elements of the 1st matrix: ";
    cout<<endl;

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr1[i][j];
        }
    }
    cout<<endl;

    int p;
    cout<<"Enter the no of rows of 2nd matrix: ";
    cin>>p;
    int q;
    cout<<"Enter the no of columns of 2nd matrix: ";
    cin>>q;

    int arr2[p][q];
    cout<<"Enter the elements of the 2nd matrix: ";
    cout<<endl;

    for(int i=0;i<p;i++) {
        for(int j=0;j<q;j++) {
            cin>>arr2[i][j];
        }
    }
    cout<<endl;

    if(n!=p) {
        cout<<"The matrices cannot be multiplied";
    }
    else {
        int res[m][q];
        for(int i=0;i<m;i++) {
            for(int j=0;j<q;j++) {
                res[i][j]=0;
                for(int k=0;k<n;k++) {
                    res[i][j]+=arr1[i][k]*arr2[k][j];
                }
            }
        }
        cout<<"The resultant of the matrices is: "<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++) {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}