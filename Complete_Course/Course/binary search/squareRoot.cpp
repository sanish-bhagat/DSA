#include<bits/stdc++.h>
using namespace std;

//sirf integer part return krrta h decimal value nhi mtlb answer more precised nhi h ya toh equal hoga ya uske aas pass

long long int squareRoot(int num) {
    int s = 0;
    int e = num;
    int mid = s + (e - s)/2;

    int ans = -1;

    while(s <= e) {

        long long int square = mid * mid;

        if(square == num) {
            return mid;
        } else if(square < num) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return mid;
}

int main() {

    int num;
    cout <<"Enter the number: ";
    cin >> num;

    cout << "The square root of " << num << " is " << squareRoot(num);
}