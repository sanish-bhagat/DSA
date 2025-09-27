#include<bits/stdc++.h>
using namespace std;
void calculateSum(int i,int sum) {
    if(i<1) {
        cout<<sum;
        return;
    }
    calculateSum(i-1,sum+i);
}
int main() {
    int n;
    cin>>n;

    calculateSum(n,0);
}