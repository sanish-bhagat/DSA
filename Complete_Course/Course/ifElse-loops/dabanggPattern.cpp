#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter no. of rows: ";
    cin>>n;

    int i=1;
    while(i<=n) {
        //1st triangle
        int j=1;
        while(j<=n-i+1) {
            cout<<j<<" ";
            j++;
        }

        //star triangle
        int k=i-1;
        while(k>0) {
            cout<<"* * ";
            k--;
        }
        int m=n-i+1;
        while(m>0) {
            cout<<m<<" ";
            m--;
        }

        cout<<endl;
        i++;
    }
}