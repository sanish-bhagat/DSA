#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter no of rows/columns: ";
    cin>>n;

    int arr[n][n];
    cout<<"Enter the elements of the array: "<<endl;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }

    cout<<endl;

    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
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

    cout<<endl;

    for(int i=0;i<n;i++) {
        int j=0;
        int k=n-1;
        while(j<k) {
            int temp=arr[i][j];
            arr[i][j]=arr[i][k];
            arr[i][k]=temp;
            j++;
            k--;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}