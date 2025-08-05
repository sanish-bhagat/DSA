#include<iostream>
#include<climits>
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


     for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    int min=INT_MAX;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(min>arr[i][j]) {
                min=arr[i][j];
            }
        }
        
    }
    
    cout<<"The min element of the matrix is: "<<min;
}