#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the no of rows: ";
    cin>>n;
    int m;
    cout<<"Enter the no of columns: ";
    cin>>m;
    cout<<"Enter the elements of the array: "<<endl;
    int arr[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    int brr[m][n];
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            brr[i][j]=arr[j][i];
            cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }
}