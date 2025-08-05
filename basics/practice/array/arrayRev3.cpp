#include<iostream>
using namespace std;
void reverse( int arr[],int a,int b) {
   for(int i=a,j=b;i<=j;i++,j--) {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
   }
}
int main()  {
    int arr[7]={1,2,3,4,5,6,7};
    reverse(arr,1,4);
    for(int i=0;i<7;i++) {
        cout<<arr[i]<<" ";
    }
}