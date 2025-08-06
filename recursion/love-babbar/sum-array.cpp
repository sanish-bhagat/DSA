#include<iostream>
using namespace std;

int getSum(int arr[],int n) {

    //base case
    if(n == 0) return 0;
    if(n == 1) return arr[0];

    int sum = arr[0] + getSum(arr + 1, n - 1);

    return sum;
}

int main() {
    int arr[5] = {2,4,5,6,7};

    cout << "Sum is " << getSum(arr,5);
}