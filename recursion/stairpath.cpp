// 1,2 STEP

#include <iostream>
using namespace std;

int stair(int n)
{
    if (n <= 2)
        return n;
    return stair(n - 1) + stair(n - 2);
}

int main()
{
    int n;
    cout << "Enter a no. : ";
    ;
    cin >> n;
    cout << stair(n);
}

// 1,2,3 STEP

// #include<iostream>
// using namespace std;
// int stair(int n) {
//     if(n<=2) return n;
//     if(n==3) return n+1;
//     return stair(n-1) + stair(n-2) +stair(n-3);
// }
// int main() {
//     int n;
//     cout<<"Enter a no. : ";;
//     cin>>n;
//     cout<<stair(n);
// }