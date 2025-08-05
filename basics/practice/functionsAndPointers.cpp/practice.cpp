// #include<iostream>
// using namespace std;
// int fact(int x) {
//     int f=1;
//     for(int i=1;i<=x;i++) {
//         f*=i;
//     }
//     return f;
// }

// int ncr(int n,int r) {
//     return fact(n)/(fact(r)*fact(n-r));
// }
// int main() {
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;
    
//     for(int i=0;i<=n;i++) {
//         for(int j=1;j<=n-i;j++) {
//             cout<<" ";
//         }
//         for(int j=0;j<=i;j++) {
//             cout<<ncr(i,j)<<" ";
//         }
//         cout<<endl;
//     }
// }






// AVERAGE


// #include<iostream>
// using namespace std;
// int avg(int a,int b,int c) {
//     return (a+b+c)/3;
// }
// int main() {
//     int a;
//     cout<<"Enter the 1st number: ";
//     cin>>a;
//     int b;
//     cout<<"Enter the 2nd number: ";
//     cin>>b;
//     int c;
//     cout<<"Enter the 3rd number: ";
//     cin>>c;

//     cout<<"The average of the numbers is: "<<avg(a,b,c);

// }






// SUM OF ODD NUMBERS


// #include<iostream>
// using namespace std;
// int sum(int n) {
//     int s=0;
//     for(int i=1;i<=n;i+=2) {
//         s+=i;
//     }
//     return s;
// }
// int main() {
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;

//     cout<<sum(n);
// }






// GREATEST


// #include<iostream>
// using namespace std;

// int main() {
//     int a;
//     cout<<"Enter 1st number: ";
//     cin>>a;
//     int b;
//     cout<<"Enter 2nd number: ";
//     cin>>b;

//     cout<<max(a,b);
// }






// CIRCUMFERENCE


// #include<iostream>
// using namespace std;
// float circum(int r) {
//     return 2*3.14*r;
// }
// int main() {
//     int r;
//     cout<<"Enter the radius of the circle: ";
//     cin>>r;

//     cout<<"The circumference of the circle is: "<<circum(r);
// }






// VOTE


// #include<iostream>
// using namespace std;
// void age(int y) {
//     if(y>18) cout<<"The person is eligible for vote.";
//     else cout<<"The person is not eligible for vote.";
// }
// int main() {
//     int y;
//     cout<<"Enter the age: ";
//     cin>>y;

//     age(y);
// }







// POWER


// #include<iostream>
// #include<cmath>
// using namespace std;

// int main() {
//     int x;
//     cout<<"Enter x: ";
//     cin>>x;
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;
//     cout<<pow(x,n);
// }






// GCD


// #include<iostream>
// using namespace std;
// int gcd(int a,int b) {
//     int g=1;
//     for(int i=1;i<=min(a,b);i++) {
//         if(a%i==0 &&  b%i==0) {
//             g=i;
//         }
//     }
//     return g;
// }
// int main() {
//     int a;
//     cout<<"Enter the 1st number: ";
//     cin>>a;
//     int b;
//     cout<<"Enter the 2nd number: ";
//     cin>>b;

//     cout<<"The gcd of "<<a<<" and "<<b<<" is: "<<gcd(a,b);
// }







// FIBONACCI SERIES


// #include<iostream>
// using namespace std;
// void fibonacci(int n) {
//     int a=0;
//     int b=1;
//     int c;
//     for(int i=1;i<=n;i++) {
//         cout<<a<<" ";
//         c=a+b;
//         a=b;
//         b=c;
//     }
// }
// int main() {
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;

//     fibonacci(n);
// }







// FACTORIAL TILL N NO


// #include<iostream>
// using namespace std;
// void fact(int n) {
//     int f=1;
//     for(int i=2;i<=n+1;i++) {
//         cout<<f<<" ";
//         f*=i;
//     }
// }
// int main() {
//     int n;
//     cout<<"Enter n: ";
//     cin>>n;

//     fact(n);
// }






#include<iostream>
using namespace std;
int fibo(int n) {
    int a=0;
    int b=1;
    int c;
    for(int i=1;i<=n;i++) {
        cout<<a<<" ";
        c=a+b;
        a=b;
        b=c;
    }
}
int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    fibo(n);
}