#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the no of rows/columns: ";
    cin>>n;
    
    cout<<"Enter the elements of the array: "<<endl;
    int arr[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }

    cout<<endl;

    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}