#include<iostream>
using namespace std;

bool search(int arr[],int size,int key) {

    for(int i=0;i<size;i++) {
        if(arr[i]==key) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int arr[6]={1,2,5,6,7,9};

    int key;
    cout<<"Enter the element to search for: ";
    cin>>key;

    if(search(arr,6,key)) {
        cout<<"Key is present";
    } else {
        cout<<"Key is not present";
    }

}