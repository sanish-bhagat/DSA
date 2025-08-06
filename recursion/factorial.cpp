#include <iostream>
using namespace std;

int factors(int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return n * factors(n - 1);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << factors(n);
}