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
    int sum=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            sum+=arr[i][j];
        }
    }
    cout<<"The sum of the matrix is: "<<sum;
}