// #include<iostream>
// using namespace std;
// int power(int a,int b) {
//     int p=1;
//     for(int i=1;i<=b;i++) {
//         p*=a;
//     }
//     return p;
// }
// int main() {
//     int a;
//     cout<<"Enter a: ";
//     cin>>a;
//     int b;
//     cout<<"Enter b: ";
//     cin>>b;
//     cout<<power(a,b);
// }





// #include<iostream>
// using namespace std;
// int power(int a,int b) {
//    if(b==0) return 1;
//    return a*power(a,b-1);
// }
// int main() {
//     int a;
//     cout<<"Enter a: ";
//     cin>>a;
//     int b;
//     cout<<"Enter b: ";
//     cin>>b;
//     cout<<power(a,b);
// }







#include<iostream>
using namespace std;
int power(int a,int b) {
   if(b==1) return a;
   int x=power(a,b/2);
   if(b%2==0) return x*x;
   else return x*x*a;   
}
int main() {
    int a;
    cout<<"Enter a: ";
    cin>>a;
    int b;
    cout<<"Enter b: ";
    cin>>b;
    cout<<power(a,b);
}