#include<bits/stdc++.h>
using namespace std;

void markRow(int arr,int m) {
    for(int j=0;j<m;j++) {
        if(arr[i][j] != 0)
        arr[i][j] = -1;
    }
}

void markCol(int arr,int n) {
    for(int i=0;i<n;i++) {
        if(arr[i][j] != 0)
        arr[i][j] = -1;
    }
}

void Zero(int arr,int n,int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == -1) {
                arr[i][j] = 0;
            }
        }
    }
}

void matrixZero(int arr[],int n,int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 0) {
                markRow(i);
                markCol(j);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the rows of the array: ";
    cin >> n;

    int m;
    cout << "Enter the column of the array: ";
    cin >> m;

    int arr[n][m];

    cout << "Enter the elements: ";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
        cin >> arr[i][j];
            
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
           cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
