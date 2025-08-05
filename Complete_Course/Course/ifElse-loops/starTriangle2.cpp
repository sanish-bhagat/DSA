#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter no. of rows: ";
    cin>>n;

    int i=1;
    

    while(i<=n) {
        int sp=n-i;
        while(sp>0) {
            cout<<"  ";
            sp--;
        }
        int j=1;
        
        while(j<=i) {
            cout<<j<<" ";
            j++;
        }
        int k=i-1;
        while(k) {
            cout<<k<<" ";
            k--;
        }
        cout<<endl;
        i++;
    }

}