// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n1;
//     cin>>n1;

//     int n2;
//     cin>>n2;

//     int gcd=1;

//     for(int i=min(n1,n2);i>=1;i--) {
//         if(n1%i==0 && n2%i==0) {
//             gcd=i;
//             break;
//         }
//     }
//     cout<<gcd;
// }



#include<bits/stdc++.h>
using namespace std;

int main() {
    int n1;
    cin>>n1;

    int n2;
    cin>>n2;

    while(n1!=0 && n2!=0) {
        if(n1>n2) n1%=n2;
        else n2%=n1;
    }
    if(n1==0) cout<<n2;
    else cout<<n1;
}