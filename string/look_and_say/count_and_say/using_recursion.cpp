#include<bits/stdc++.h>
using namespace std;

//! TC is O(n * n)

string countnndSay(int n) {

    //base case condition
    if(n == 1)
        return "1";

    string say = countnndSay(n - 1);

    string res = "";

    //say string pr processing krro
    for(int i = 0; i<say.length(); i++) {

        char ch = say[i];
        int count = 1;

        //count krrte characters k freq ko
        while(i < say.length() - 1 && say[i] == say[i + 1])
            count++, i++;

        //res mein add krro in the form = "(count) bar likha h (char)"
        res += to_string(count) + string(1, ch);
    }

    return res;
}

int main()
{
    int N = 3;
    cout << countnndSay(N) << endl;
    return 0;
}