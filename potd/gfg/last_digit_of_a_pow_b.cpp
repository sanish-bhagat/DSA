#include <bits/stdc++.h>
using namespace std;

int modulo(int a, string b)
{
    int mod = 0;

    // calculate (b mod a) to make
    // b in range 0 <= b < a
    for (int i = 0; i < b.size(); i++)
    {
        mod = (mod * 10 + b[i] - '0') % a;
    }

    return mod;
}

//! TC is O(|b|)
//! SC is O(1)

int getLastDigit(string &a, string &b)
{
    int len_a = a.size(), len_b = b.size();

    // base is 0 -> return 0
    if (len_a == 1 && a[0] == '0')
        return 0;

    // exponent is 1 -> a ^ 0 = 1
    if (len_b == 1 && b[0] == '0')
        return 1;

    int mod = modulo(4, b);

    // if exponent is divisible by 4 that means last
    // digit will be pow(a, 4) % 10
    // otherwise last digit will be pow(a, b%4) % 10
    int ex = (mod == 0) ? 4 : mod;

    int res = pow(a[len_a - 1] - '0', ex);

    return res % 10;
}

int main()
{
    string a = "8";
    string b = "6";

    cout << getLastDigit(a, b);
}