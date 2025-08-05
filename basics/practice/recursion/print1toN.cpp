// EXTRA PARAMETER


// #include<iostream>
// using namespace std;

// void print(int x,int n) {
//     if(x>n) return;
//     cout<<x<<" ";
//     print(x+1,n);
// }
// int main() {
//     int n;
//     cout<<"Enter the number: ";
//     cin>>n;
//     print(1,n);
// }






#include<iostream>
using namespace std;

void print(int n) {
    if(n==0) return;
    print(n-1);
    cout<<n<<" ";
    
}
int main() {
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    print(n);
}