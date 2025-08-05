// #include<bits/stdc++.h>
// using namespace std;

// void selection_sort(int arr[],int n) {
//     for(int i=0;i<n-1;i++) {
//         int mini=i;
//         for(int j=i;j<n;j++) {
//             if(arr[j]<arr[mini]) mini=j;
//         }
//         int temp=arr[i];
//         arr[i]=arr[mini];
//         arr[mini]=temp;
//     }
// }

// void bubble_sort(int arr[],int n) {
//     for(int i=n-1;i>=0;i--) {
//         int didSwap=0;
//         for(int j=0;j<=i-1;j++) {
//             if(arr[j]>arr[j+1]) {
//                 int temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//                 didSwap=1;
//             }
//         }
//         if(didSwap==0) break;
//     }
// }

// void insertion_sort(int arr[],int n) {
//     for(int i=0;i<n;i++) {
//         int j=i;

//         while(j>0 && arr[j]<arr[j-1]) {
//             int temp=arr[j];
//             arr[j]=arr[j-1];
//             arr[j-1]=temp;
//             j--;
//         }
//     }
// }

// int main() {
//     int n;
//     cout<<"Enter the size of the array: ";
//     cin>>n;

//     int arr[n];
//     cout<<"Enter the elements of the array: ";
//     for(int i=0;i<n;i++) {
//         cin>>arr[i];
//     }

//     insertion_sort(arr,n);
//     for(int i=0;i<n;i++) {
//         cout<<arr[i]<<" ";
//     }
// }





#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low,int mid, int high) {
    vector<int> temp;
    int left=low;
    int right=mid+1;

    while(left<=mid && right<=high) {
        if(arr[left]<=arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++) {
        arr[i]=temp[i-low];
    } 
}

void sort(vector<int> &arr,int low,int high) {
    if(low==high) return;
    int mid=(low+high)/2;
    sort(arr,low,mid);
    sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void merege_sort(vector<int> &arr,int n) {
    sort(arr,0,n-1);
}

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr;
    int element;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++) {
        cin>>element;
        arr.push_back(element);
    }

    merege_sort(arr,n);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}