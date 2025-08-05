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


    int max=INT_MIN;
    int idx1=-1;
    int idx2=-1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(max<arr[i][j]) {
                max=arr[i][j];
                idx1=i;
                idx2=j;
            }
           
        }
    }

    cout<<"The max element of the matrix is: "<<max<<endl;
    cout<<idx1<<","<<idx2;
}