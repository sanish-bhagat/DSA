#include<bits/stdc++.h>
using namespace std;

int getLength(char arr[]) {
    int cnt = 0;

    for(int i=0; arr[i] != '\0'; i++) {
        cnt++;
    }
    return cnt;
}

int main() {
    char name[20];
    cout << "Enter your name : ";
    cin >> name;

    cout << "Length : " << getLength(name);
}