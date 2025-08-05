#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the size: ";
    cin>>n;

    int arr[100];
    cout<<"Enter the elemnts of the array: "<<endl;
    
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<endl;

    int sum=0;

    for(int i=0;i<n;i++) {
        sum+=arr[i];
    }
    cout<<"The sum of the array is: "<<sum;
}