#include<iostream>
using namespace std;
void preInPost(int n) {
    if(n==0) return;
    cout<<n;
    preInPost(n-1);
    cout<<n;
    preInPost(n-1);
    cout<<n;
    return;
}
int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    preInPost(n);
}