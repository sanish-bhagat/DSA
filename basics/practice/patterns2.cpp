// STAR PLUS " "


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the no. of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n;j++) {
//             if(i==(n/2)+1 || j==(n/2)+1) {
//                 cout<<"* ";
//             } else{ 
//                 cout<<"  ";
//             }
//         }
//         cout<<endl;
//     }
// }





// HOLLOW RECTANGLE


// #include<iostream>
// using namespace std;

// int main() {
//     int n,m;
//     cout<<"Enter the number of rows: ";
//     cin>>n;
//     cout<<"Enter the number of cols: ";
//     cin>>m;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=m;j++) {
//             if(i==1 || i==n || j==1 || j==m) {
//                 cout<<"* ";
//             } else {
//                 cout<<"  ";
//             }
//         }
//         cout<<endl;
//     }
// }





// STAR CROSS


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=0;i<n;i++) {
//         for(int j=0;j<n;j++) {
//             if(i==j || i+j==n-1) {
//                 cout<<"*";
//             } else {
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }





// STAR TRIANGLE REVERSE


//  #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n-i;j++) {
//             cout<<" ";
//         }
//         for(int j=1;j<=i;j++) {
//             cout<<"*";
//         }
//         cout<<endl;
//     }
// }





// NUMBER TRIANGLE REVERSE


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n-i;j++) {
//             cout<<"  ";
//         }
//         for(int j=1;j<=i;j++) {
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
// }






// ALPHABET TRIANGLE REVERSE


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n-i;j++) {
//             cout<<"  ";
//         }
//         for(int j=1;j<=i;j++) {
//             cout<<(char)(j+64)<<" ";
//         }
//         cout<<endl;
//     }
// }





// STAR RHOMBUS


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n-i;j++) {
//             cout<<"  ";
//         }
//         for(int j=1;j<=n;j++) {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }





// STAR PYRAMID


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n-i;j++) {
//             cout<<" ";
//         }
//         for(int j=1;j<=i;j++) {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }





// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n-i;j++) {
//             cout<<" ";
//         }
//         for(int j=1;j<=i;j++) {
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
// }



// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cin>>n;

//     for(int i=n;i>=1;i--) {
//        for(int j=0;j<=n-i;j++) {
//         cout<<"  ";
//        }
//        for(int j=1;j<=i;j++) {
//         cout<<"* ";
//        }
//        for(int j=2;j<=i;j++) {
//         cout<<"* ";
//        }
//        cout<<endl;
//     }
// }





// #include<Iostream>
// using namespace std;

// int main() {
//     int n;
//     cin>>n;

//     for(int i=0;i<n;i++) {
//         for(int j=n-i;j>=0;j--) {
//             cout<<"  ";
//         }
//         for(int j=0;j<=i;j++) {
//             cout<<(char)(j+65)<<" ";
//         }
//         int a=i-1;
//         for(int j=1;j<=i;j++) {
//             cout<<(char)(a+65)<<" ";
//             a--;
//         }
//         cout<<endl;
//     }
// }




#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a=0;

    
    int nsp=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i;j++) {
            cout<<"* ";
        }
        for(int j=0;j<nsp;j++) {
            cout<<"  ";
            
        }
        for(int j=0;j<n-i;j++) {
            cout<<"* ";
        }
        nsp+=2;
        cout<<endl;
    }

    int nsp2=8;

     for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            cout<<"* ";
        }
        for(int j=0;j<nsp;j++) {
            cout<<"  ";
            
        }
        for(int j=0;j<i;j++) {
            cout<<"* ";
        }
        nsp2-=2;
        cout<<endl;
    }
}