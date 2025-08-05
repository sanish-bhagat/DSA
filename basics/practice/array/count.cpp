#include<iostream>
using namespace std;

int main() {
    int arr[7]={1,2,5,3,4,5,9};
    int count=0;
     for(int i=0;i<=6;i++) {
        cout<<arr[i]<<" ";
    }
    int x;
    cout<<endl<<"Enter a number: ";
    cin>>x;
    for(int i=0;i<=6;i++) {
        if(arr[i]>x) 
        count++;
    }
    cout<<count<<endl;
}