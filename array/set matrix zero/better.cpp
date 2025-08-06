#include<bits/stdc++.h>
using namespace std;

//TC is O(2*n*m)
//SC is O(n + m)

void display(int arr[][100],int n,int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
           cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void zeroMatrix(int arr[][100],int n,int m) {
    int col[m] = {0};
    int row[n] = {0};

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }

    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(row[i] || col[j] == 1) {
                arr[i][j] = 0;
            }
        }        
    }

    
    display(arr,n,m);
}

int main() {
    int n;
    cout << "Enter the rows of the array: ";
    cin >> n;

    const int MAX_SIZE = 100;

    int m;
    cout << "Enter the column of the array: ";
    cin >> m;

    int arr[MAX_SIZE][MAX_SIZE];

    cout << "Enter the elements: ";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
        cin >> arr[i][j];
            
        }
    }

    zeroMatrix(arr,n,m);

}
