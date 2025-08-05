#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the no of rows: ";
    cin>>n;
    int m;
    cout<<"Enter the no of columns: ";
    cin>>m;

    int arr[n][m];
    cout<<"Enter the elements of the array: "<<endl;

    //input elements
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<endl;

    int minr=0;
    int maxr=n-1;
    int minc=0;
    int maxc=m-1;
    int tne=n*m;
    int count=0;

    while(count<tne) {
        //min row
        for(int j=minc;j<=maxc;j++) {
            cout<<arr[minr][j]<<" ";
            count++;
        }
        minr++;
       if(count>=tne){
        break;
       }

        //max column
        for(int i=minr;i<=maxr;i++) {
            cout<<arr[i][maxc]<<" ";
            count++;
        }
        maxc--;
        if(count>=tne){
        break;
       }

        //max row
        for(int j=maxc;j>=minc;j--) {
            cout<<arr[maxr][j]<<" ";
            count++;
        }
        maxr--;
        if(count>=tne){
        break;
       }


        //min column
        for(int i=maxr;i>=minr;i--) {
            cout<<arr[i][minc]<<" ";
            count++;
        }
        minc++;
        if(count>=tne){
        break;
       }

    }
}