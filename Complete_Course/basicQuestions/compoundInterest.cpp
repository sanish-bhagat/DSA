#include<iostream>
#include<cmath>
using namespace std;

int main() {
    double p=25000,r=12,t=5;
   

    double a=p*((pow((1+r/100),t)));

    double ci=a-p;

    cout<<ci;
}