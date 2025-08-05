// #include<iostream>
// using namespace std;

// int main() {
//     int arr[3][3]={1,0,1,1,1,1,0,1,0};
//     for(int i=0;i<3;i++) {
//         for(int j=0;j<3;j++) {
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }

//     int maxSum=0;
//     int idx=-1;
//     for(int i=0;i<3;i++) {
//         int sum=0;
//         for(int j=0;j<3;j++) {
//             sum+=arr[i][j];
//         }
//         if(maxSum<sum) {
//             maxSum=sum;
//             idx=i;
//         }
//     }
//     cout<<maxSum<<endl;
//     cout<<idx;
// }






#include<iostream>
using namespace std;

int main() {
    int arr[3][3]={1,0,0,1,0,1,0,1,0};
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int maxCount=0;
    int idx=-1;
    for(int i=0;i<3;i++) {
        int count=0;
        for(int j=0;j<3;j++) {
            if(arr[i][j]==1) {
            count ++;
           }
            if(maxCount<count) {
                maxCount=count;
                idx=i;
            }
        }
        
    }
    cout<<maxCount<<endl;
    cout<<idx;
}