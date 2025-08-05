#include<iostream>
using namespace std;

void sum(int x,int n) {
    if(x>n) return;
    sum(x+1,n);
    cout<<x+n<<" ";
}
int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    sum(1,n);
}