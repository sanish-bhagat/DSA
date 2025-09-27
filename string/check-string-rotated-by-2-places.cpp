#include<bits/stdc++.h>
using namespace std;

void rotateClockwise(string &s) {
    char c = s[s.size() - 1];
    int index = s.size() - 2;

    while(index >= 0) {
        s[index + 1] = s[index];
        index--;
    }
    s[0] = c;
}

void rotateAnticlockwise(string &s) {
    char c = s[0];
    int index = 1;

    while(index < s.size()) {
        s[index - 1] = s[index];
        index++;
    }
    s[s.size() - 1] = c;
}

bool isRotated(string &s1 , string &s2) {
    if(s1.size() != s2.size()) return 0;

    string clockwise , anticlockwise;

    clockwise = s1;
    rotateClockwise(clockwise);
    rotateClockwise(clockwise);

    if(clockwise == s2) return 1;

    anticlockwise = s1;
    rotateAnticlockwise(anticlockwise);
    rotateAnticlockwise(anticlockwise);

    if(anticlockwise == s2) return 1;

    return 0;
}

int main() {
    string s1 = "amazon" , s2 = "azonam";

    cout << isRotated(s1,s2);
}