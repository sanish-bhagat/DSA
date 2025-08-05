#include <Iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the terms: ";
    cin >> n;

    int a = 0;
    int b = 1;
    int c;

    for (int i = 0; i < n; i++)
    {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
}