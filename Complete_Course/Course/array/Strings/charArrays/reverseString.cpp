#include<iostream>
using namespace std;

void reverseString(char name[],int n) {
    int s = 0;
    int e = n - 1;

    while(s<e) {
        swap(name[s++],name[e--]);
    }
}

int getLength(char name[]) {   // to get the length of the string
    int count = 0;

    for(int i=0;name[i] != '\0';i++) {
        count++;
    }
    return count;
}

int main() {
    char name[20];
    cout << "Enter your name: " << endl;
    cin >> name;

    cout << "Your name is " << name << endl;

    reverseString(name,getLength(name));

    cout << "Your reverse name is " << name;
}