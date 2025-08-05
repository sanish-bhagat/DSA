// ODD NO TRIANGLE


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





// ALPHABET TRIANGLE


//  #include<iostream>
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






// NO AND ALPHABET TRAINGLE


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






// STAR PLUS 


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n;j++) {
//             if(i==(n/2)+1 || j==(n/2)+1) {
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

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n;j++) {
//             if(i==j || i+j==n+1) {
//                 cout<<"* ";
//             } else {
//                 cout<<"  ";
//             }
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

//     int a=1;
//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             cout<<a<<" ";
//             a+=1;
//         }
//         cout<<endl;
//     }
// }





// ODD NO


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     int a=1;
//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             cout<<a<<" ";
//             a+=2;
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






// STAR PYRAMID


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
//         for(int j=1;j<=(2*i-1);j++) {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }






// ALPHABET PYRAMID


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
//         for(int j=1;j<=(2*i-1);j++) {
//             cout<<(char)(j+64)<<" ";
//         }
//         cout<<endl;
//     }
// }






// NUMBER PYRAMID


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
//         for(int j=1;j<=(2*i-1);j++) {
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
// }






// **NUMBER PYRAMID


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
//         int a=i-1;
//         for(int j=1;j<=i-1;j++) {
//             cout<<a<<" ";
//             a--;
//         }
//         cout<<endl;
//     }
// }





// **ALPHABET PYRAMID


#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n-i;j++) {
            cout<<"  ";
        }
        for(int j=1;j<=i;j++) {
            cout<<(char)(j+64)<<" ";
        }
        int a=i-1;
        for(int j=1;j<=i-1;j++) {
            cout<<(char)(a+64)<<" ";
            a--;

        }
        cout<<endl;
    }
}





// STAR DIAMOND


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     int nst=1;
//     int nsp=n/2;
//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=nsp;j++) {
//             cout<<"  ";
            
//         }
//         for(int j=1;j<=nst;j++) {
//             cout<<"* ";
            
//         }
//         if(i<n/2 +1) {
//             nst+=2;
//             nsp--;
//         } else {
//             nsp++;
//             nst-=2;
//         }
//         cout<<endl;
//     }
// }





// STAR TRAINGLE REVERSE


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     int nsp=0;
//     int nst=n;
//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=nsp;j++) {
//             cout<<"  ";
//         }
//         for(int j=1;j<=nst;j++) {
//             cout<<"* ";
//         }
//         nsp++;
//         nst--;
//         cout<<endl;
//     }
// }








// **NUMBER PYRAMID


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     int nsp=1;
//     int nst=n;

//     for(int i=1;i<=2*n+1;i++) {
//         cout<<"* ";
//     }
//     cout<<endl;
//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=nst;j++) {
//             cout<<"* ";
//         }
//         for(int j=1;j<=nsp;j++) {
//             cout<<"  ";
//         }
//         for(int j=1;j<=nst;j++) {
//             cout<<"* ";
//         }
//         nsp+=2;
//         nst--;
//         cout<<endl;
//     }
// }






// ***APLHABET PYARMID


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;
//     int m=n-1;

//     int nsp=1;
//     int num=m;

//     for(int i=1;i<=2*n-1;i++) {
//         cout<<(char)(i+64);
//     }
//     cout<<endl;

//     for(int i=1;i<=m;i++) {
//         int a=1;
//         for(int j=1;j<=num;j++) {
//             cout<<(char)(a+64);
//             a++;
//         }
//         for(int j=1;j<=nsp;j++) {
//             cout<<" ";
//             a++;
//         }
//         for(int j=1;j<=num;j++) {
//             cout<<(char)(a+64);
//             a++;
//         }
//         num--;
//         nsp+=2;
//         cout<<endl;
//     }
// }







// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     int m=n-1;

//     int nsp=1;
//     int num=m;

//     for(int i=1;i<=2*n-1;i++) {
//         cout<<i<<" ";
//     }
//     cout<<endl;


//     for(int i=1;i<=m;i++) {
//         int a=1;
//         for(int j=1;j<=num;j++) {
//             cout<<a<<" ";
//             a++;
//         }
//         for(int j=1;j<=nsp;j++) {
//             cout<<"  ";
//             a++;
//         }
//         for(int j=1;j<=num;j++) {
//             cout<<a<<" ";
//             a++;
//         }
//         num--;
//         nsp+=2;
//         cout<<endl;
//     }
// }







// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of rows: ";
//     cin>>n;

//     int m=n-1;

//     int nsp=1;
//     int num=m;

//     for(int i=1;i<=m;i++) {
//         int a=1;

//         for(int j=1;j<=num;j++) {
//             cout<<a<<" ";
//             a++;
//         }
//         for(int j=1;j<=nsp;j++) {
//             cout<<"  ";
            
//         }
//         int b=1;
//         for(int j=1;j<=num;j++) {
//             cout<<b<<" ";
//             b++;
//         }
//         num--;
//         nsp+=2;
//         cout<<endl;
//     }
// }





// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of lines: ";
//     cin>>n;

//     int nst=1;
//     int nsp=n/2;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=nsp;j++) {
//             cout<<"  ";
//         }
//         for(int j=1;j<=nst;j++) {
//             cout<<"* ";
//         }
//         if(i<n/2+1) {
//             nst+=2;
//             nsp--;
//         } else {
//             nst-=2;
//             nsp++;
//         }
//         cout<<endl;
//     }
// }






// STAR BUTTERFLY


// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of lines: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=i;j++) {
//             cout<<"* ";
//         }
//         for(int j=1;j<=2*(n-i);j++) {
//             cout<<"  ";
//         }
//         for(int j=1;j<=i;j++) {
//             cout<<"* ";
//         }
//         cout<<endl;    
//     }

//     for(int i=n;i>=1;i--) {
//         for(int j=1;j<=i;j++) {
//             cout<<"* ";
//         }
//         for(int j=1;j<=2*(n-i);j++) {
//             cout<<"  ";
//         }
//         for(int j=1;j<=i;j++) {
//             cout<<"* ";
//         }
//         cout<<endl;
// }
// }






// #include<iostream>
// using namespace std;

// int main() {
//     int n;
//     cout<<"Enter the number of lines: ";
//     cin>>n;

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n-i;j++) {
//             cout<<"  ";
//         }
//         for(int j=i;j>=1;j--) {
//             cout<<j<<" ";
//         }
//         for(int j=2;j<=i;j++) {
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
// }