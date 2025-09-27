#include<iostream>
#include<stack>
using namespace std;

//TC is O(N)
//SC is O(N)

int main() {
    string str = "sanish";

    stack<char> s;

    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";

    while(!s.empty()) {
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }

    cout << "Answer is: " << ans << endl;
}