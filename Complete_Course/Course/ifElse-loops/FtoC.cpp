#include<iostream>
using namespace std;

int main() {
    float f;
    cout<<"Enter the temperature in fahrenheit: ";
    cin>>f;
    
    float c;
    c=(f-32)*5/9;
    cout<<"The temperature in celsius is: "<<c;
}