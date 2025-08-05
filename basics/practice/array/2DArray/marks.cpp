#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter no of students: ";
    cin>>n;
    int arr[n][3];
    for(int i=0;i<n;i++) {
        for(int j=0;j<5;j++) {            
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<5;j++) {            
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}