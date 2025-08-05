#include<iostream>
using namespace std;

//TC is O(N)
//SC is O(1) 

char getMaxOcc(string s) {
    int arr[26] = {0};

    //chracters ka count store krrne k liye array
    for(int i=0;i<s.length();i++) {
        char ch = s[i];

        int number = 0;

        //lowercase k liye
        if(ch >= 'a' && ch <= 'z') {
            number = ch - 'a';
        } else {  //uppercase k liye
            number = ch - 'A';
        }
        arr[number]++;
    }

    int maxi = -1,ans = 0;

    //max occurence store krrne k liye
    for(int i=0;i<26;i++) {
        if(maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
    }

    //'a' + krrne pr character ka pta chlega
    return 'a' + ans;
}

int main() {
    string s;
    cin >> s;

    cout << getMaxOcc(s);
}