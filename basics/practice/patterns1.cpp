// PATTERN OF *


// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cout<<"Enter number of rows: ";
//    cin>>n;
    

//    for(int i=1;i<=n;i++) {
//     for(int j=1;j<=n;j++) {
//         cout<<"* ";
//     }
//     cout<<endl;
//    }

// }





// PATTERN OF 12345


// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cout<<"Enter number of rows: ";
//    cin>>n;
    

//    for(int i=1;i<=n;i++) {
//     for(int j=1;j<=n;j++) {
//         cout<<j;
//     }
//     cout<<endl;
//    }

// } 




// PATTERN OF ABCD


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n;j++) {
//             cout<<(char)(j+64)<<" ";
//         }
//         cout<<endl;
//     }
// }





// PATTERN OF abcde


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n;j++) {
//             cout<<(char)(j+96)<<" ";
//         }
//         cout<<endl;
//     }
// }




// PATTERN OF AAAAA


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n;j++) {
//             cout<<(char)(i+64)<<" ";
//         }
//         cout<<endl;
//     }
// }






// PATTERN OF STAR TRIANGLE


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }





// PATTERN OF NUMBER TRAINGLE


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
// }






// PATTERN OF ALPHABET TRIANGLE


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             cout<<(char)(j+64)<<" ";
//         }
//         cout<<endl;
//     }
// }






// PATTERN FOR NUMBER+ALPHABET TRIANGLE


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             if(i%2==0) {
//                 cout<<(char)(j+64)<<" ";
//             } else {
//                 cout<<j<<" ";
//             }
//         }
//         cout<<endl;
//     }
// }






// PATTERN FOR INVERTED STAR TRIANGLE


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=n;i>=1;i--) {
//         for(int j=1;j<=i;j++) {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }


// ALTERNATE METHOD


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n-i+1;j++) {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }






// INVERTED NUMBER TRIANGLE (J)


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=n;i>=1;i--) {
//         for(int j=1;j<=i;j++) {
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
// }





// INVERTED TRIANGLE (I)


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=n;i>=1;i--) {
//         for(int j=1;j<=i;j++) {
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }
// }





// **PATTERN FOR (n-j+1)


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             cout<<n-j+1<<" ";
//         }
//         cout<<endl;
//     }
// }






// INVERTED ALPHABET TRIANGLE


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=n;i>=1;i--) {
//         for(int j=1;j<=i;j++) {
//             cout<<(char)(j+64)<<" ";
//         }
//         cout<<endl;
//     }
// }






// ODD NO TRIANGLE


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             cout<<2*j-1<<" ";
//         }
//         cout<<endl;
//     }
// }


// ALTERNATE METHOD

// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         int a=1;
//         for(int j=1;j<=i;j++) {
//             cout<<a<<" ";
//             a+=2;
//         }
//         cout<<endl;
//     }
// }






// FLOYD TRIANGLE


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;
//     int  num=1;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             cout<<num<<" ";
//             num++;
//         }
//         cout<<endl;
//     }
// }






// 0&1 TRIANGLE


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;
    
//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             int sum=i+j;
//             if(sum%2==0) {
//                 cout<<"1 ";
//             } else {
//                 cout<<"0 ";
//             }
//         }
//         cout<<endl;
//     }
// }






