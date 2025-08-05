// #include<iostream>
// using namespace std;

// bool even(int n) {
//     bool flag=0;

//     if(n%2==0) {
//         flag=1;    
//     }

//     return flag;
// }

// int main() {
//     int n;
//     cout<<"Enter a no. : ";
//     cin>>n;

//     if(even(n)) {
//         cout<<"no is even";
//     } else {
//         cout<<"not even";
//     }

// }


#include<iostream>
using namespace std;

bool even(int n) {
    bool flag=1;

    if(n&1) {
        flag=0;    
    }

    return flag;
}

int main() {
    int n;
    cout<<"Enter a no. : ";
    cin>>n;

    if(even(n)) {
        cout<<"No is even";
    } else {
        cout<<"No is odd";
    }

}