#include<iostream>
using namespace std;

int main() {
    int amount;
    cout<<"Enter the amount: ";
    cin>>amount;

    int notes=1;
    
    int r=amount;

    switch(notes) {
        case 1:{
            notes=r/100;
            r%=100;
            cout<<"no. of 100/- notes: "<<notes<<endl;
        }

        case 2:{
            notes=r/50;
            r%=50;
            cout<<"no. of 50/- notes: "<<notes<<endl;
        }
        case 3:
            notes=r/20;
            r%=20;
            cout<<"no. of 20/- notes: "<<notes<<endl;

        case 4:
            notes=r/10;
            r%=10;
            cout<<"no. of 10/- notes: "<<notes<<endl;
    }

}