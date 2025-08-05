// #include<iostream>
// using namespace std;
// bool palindrome(int arr[]) {
//     int i=0;
//     int j=6;
//     while(i<j) {
//         if(arr[i]!=arr[j]) {return false;
//         }
       
//     }
//     i++;
//     j--;
//     return true;
// }
// int main() {
//     int arr[7]={1,2,3,4,3,2,1};
//     palindrome(arr);
//     if(palindrome(arr)) {
//         cout<<"palindrome"<<endl;
//     } else {
//         cout<<"not"<<endl;
//     }
// }




#include<iostream>
using namespace std;
bool palindrome(int arr[]) {
    int i=0;
    int j=4;
    while(i<j) {
        if(arr[i]!=arr[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main() {
    int arr[5]={1,2,3,4,1};
    if(palindrome(arr)) {
        cout<<"palindrome";
    } else{
        cout<<"Not palindromne";
    }
}