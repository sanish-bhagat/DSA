
// PERMUTATION FUNCTION


// #include<iostream>
// using namespace std;

// int fact(int x) {
//     int f=1;
//     for(int i=1;i<=x;i++) {
//         f *=i;
//     }
//     return f;
// }
// int main() {
//     int n;
//     cout<<"Enter the number: ";
//     cin>>n;
//     int r;
//     cout<<"Enter the number: ";
//     cin>>r;

//     int a= fact(n);
//     int b= fact(n-r);
//     cout<<a/b;
// }






#include<iostream>
using namespace std;
int fact(int x) {
    int f=1;
for(int i=1;i<=x;i++) {
    f*=i;
 }
 return f;
}

int ncr(int n,int r) {
    return fact(n)/(fact(r)*fact(n-r));
}
int main() {

    int n;
    cout<<"Enter n: ";
    cin>>n;

    for(int i=0;i<=n;i++) {
        for(int j=1;j<=n-i;j++) {
            cout<<" ";
        }
        for(int j=0;j<=i;j++) {
            cout<<ncr(i,j)<<" ";
        }
        cout<<endl;
    }
}