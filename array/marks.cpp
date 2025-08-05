#include<iostream>
using namespace std;

int main(){
    int arr[5];
    for(int i=0;i<=4;i++) {
        cout<<"Enter the marks of the "<<i+1<<" student: ";
        cin>>arr[i];
    }
    for(int i=0;i<=4;i++) {
        if(arr[i]<35){
            cout<<"The roll no. of the student with less than 35 marks is "<<i<<"."<<endl;
        }
    }
}


