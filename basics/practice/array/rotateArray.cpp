// #include<iostream>
// using namespace std;
// void reverse(int arr[],int a,int b) {
//     for(int i=a,j=b;i<=j;i++,j--) {
//         int temp=arr[i];
//         arr[i]=arr[j];
//         arr[j]=temp;
//     }
// }
// int main() {
//     int arr[7]={1,2,3,4,5,6,7};
//     int n=7;
//     int k=50;
//     k=k%n;
//     reverse(arr,0,n-1);
//     reverse(arr,0,k-1);
//     reverse(arr,k,n-1);
//     for(int i=0;i<7;i++) {
//         cout<<arr[i]<<" ";
//     }
// }




#include<iostream>
using namespace std;
void reverse(int arr[],int a,int b) {
    for(int i=a,j=b;i<=j;i++,j--) {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    return;
}
int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cout<<"Enter the "<<i<<" element: ";
        cin>>arr[i];
       
    }
    int k;
    cout<<"Enter the number of times to rotate: ";
    cin>>k;
    k=k%n;
    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);

    for(int i=0;i<7;i++) {
        cout<<arr[i]<<" ";
    }
}