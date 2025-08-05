// #include<iostream>
// using namespace std;
// void sum(int n,int s) {
//     if(n==0) {
//         cout<<s;
//         return;
//     }
//     sum(n-1,s+n);
//     return;
// }
// int main() {
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;
//     sum(n,0);
// }




#include<iostream>
using namespace std;
int sum(int n) {
   if(n==0 || n==1) return n; 
   return n+sum(n-1);
}
int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<sum(n);
}