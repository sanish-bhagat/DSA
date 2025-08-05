// #include<iostream>
// using namespace std;

// int main() {
//    int a;
//    int b;
//    cout<<"Enter the first no. : ";
//    cin>>a;
//    cout<<"Enter the second no. : ";
//    cin>>b;

//    int sum=a+b;
//    cout<<"The sum of the numbers is : "<<sum;
//    return 0;

// }
   

// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cin>>n;

//    if(n%2==0) {
//       cout<<"Number is even";
//    } else{
//       cout<<"Number is odd";
//    }
//    return 0;
// }



// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cout<<"Enter a positive number: ";
//    cin>>n;

//    if(n%5==0) {
//       cout<<"Number is divisble by 5";
//    }
//    else {
//       cout<<"Number is not divisible by 5";
//    }
//    return 0;
// }



// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cout<<"Enter a number: ";
//    cin>>n;

//    if(n>=0) {
//       cout<<n;
//    } else{
//       cout<<-n;
//    }
//    return 0;
// }


// #include<iostream>
// using namespace std;

// int main() {
//    int cp;
//    cout<<"Enter the cost price of the product: ";
//    cin>>cp;

//    int sp;
//    cout<<"Enter the selling price of the item: ";
//    cin>>sp;

//    int profit=sp-cp;
//    int loss=cp-sp;

//    if(cp<sp) {
//       cout<<"Profit:"<< profit;
//    } else if(cp==sp){
//       cout<<"No Profit or Loss";
//    } else{
//       cout<<"Loss:"<<loss;
//    }
//    return 0;
// }


// #include<iostream>
// using namespace std;

// int main() {
//    int l;
//    cout<<"Enter the length of the rectangle: ";
//    cin>>l;

//    int b;
//    cout<<"Enter the breadth of the rectangle: ";
//    cin>>b;

//    int area=l*b;
//    int perimeter=2*(l+b);

//    if(area>perimeter) {
//       cout<<"Area is greater";
//    } else{
//       cout<<"Perimeter is greater";
//    }
//    return 0;
// }


// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cout<<"Enter a postive number: ";
//    cin>>n;

//    if(n%5==0 && n%3==0) {
//       cout<<"Number is divisible by 5 and 3";
//    } else{
//       cout<<"Number is not divisible by 5 and 3";
//    }
//    return 0;
// }



// #include<iostream>
// using namespace std;

// int main() {
//    int a,b,c;
//    cout<<"Enter the first no. : ";
//    cin>>a;

//    cout<<"Enter the second no. :";
//    cin>>b;

//    cout<<"Enter the third no. :";
//    cin>>c;

//    if(a>b &&a>c) {
//       cout<<"a is greater";
//    } else if(b>a && b>c) {
//       cout<<"b is greater";
//    } else{ 
//       cout<<"c is greater";
//    }
//    return 0;
// }



// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cout<<"Enter a positive number: ";
//    cin>>n;

//    if((n%5==0 || n%3==0)  &&  (n%15!=0)) {
//       cout<<"Valid";
//    } else{
//       cout<<"Invalid";
//    }
//    return 0;
// }



// #include<iostream>
// using namespace std;

// int main() {
//    int r,s,a;

//    cout<<"Enter the age of Ram: ";
//    cin>>r;
//    cout<<"Enter the age of Shyam: ";
//    cin>>s;
//    cout<<"Enter the age of Ajay: ";
//    cin>>a;

//    if(r<s) {
//       if(r<a) {
//          cout<<"Ram is youngest";
//       } else{
//          cout<<"Ajay is youngest";
//       }
//    } else{
//       if(s<a) {
//          cout<<"Shyam is youngest";
//       } else{
//          cout<<"Ajay is youngest";
//       }
//    }
//    return 0;
// }




// #include<iostream>
// using namespace std;

// int main() {
//    int p;
//    cout<<"Enter the percentage of the student: ";
//    cin>>p;

//    if(p>=81 && p<=100) {
//       cout<<"Very Good";
//    } else if(p>=61 && p<=80) {
//       cout<<"Good";
//    } else if(p>=41 && p<=60) {
//       cout<<"Average";
//    } else{
//       cout<<"Fail";
//    }
//    return 0;
// }




// #include<iostream>
// using namespace std;

// int main() {
//    int x,y;
//    cout<<"Enter the first point: ";
//    cin>>x;
//    cout<<"Enter the second point: ";
//    cin>>y;

//    if(x>0 && y>0) {
//       cout<<"Point lies on the first quadrant.";
//    } else if(x>0 && y<0) {
//       cout<<"Point lies on the fourth quadrant.";
//    } else if(x<0 && y>0) {
//       cout<<"Point lies on the second quadrant.";
//    } else if(y==0) {
//       cout<<"Point lies on x-axis.";
//    } else if(x<0 && y<0) {
//       cout<<"Point lies on the third quadrant.";
//    } else {
//       cout<<"Point lies on the y-axis.";
//    }
//    return 0;
// }



// #include<iostream>
// using namespace std;

// int main() {
//    int n1;
//    cout<<"Enter the first number: ";
//    cin>>n1;
//    int n2;
//    cout<<"Enter the second number: ";
//    cin>>n2;

//    char op;
//    cout<<"Enter the operation to be performed(+ - * /): ";
//    cin>>op;

//    switch(op) {
//       case '+':
//          cout<<n1+n2;
//          break;
//       case '-':
//          cout<<n1-n2;
//          break;
//       case '*':
//          cout<<n1*n2;
//          break;
//       case '/':
//          cout<<n1/n2;
//          break;
//       default:
//          cout<<"Invalid";
//    }
//    return 0;
// }



// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cin>>n;

//    for(int i=1;i<=n;i++) {
//       cout<<"Hello World!\n";
//    }
//    return 0;
// }



// #include<iostream>
// using namespace std;

// int main() {
//    for(int i=1;i<=100;i++) {
//       cout<<i<<endl;
//    }
//    return 0;
// }



// #include<iostream>
// using namespace std;

// int main() {
 
//    for(int i=1;i<=100;i++) {
//        if(i%2!=0) {
//          cout<<i;
//       } else{
//          cout<<" ";
//       }
//    }
// }



// #include<iostream>
// using namespace std;

// int main() {
 
//    for(int i=2;i<=100;i=i+2) {
       
//          cout<<i<<" ";
   
//    }
// }


// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cout<<"Enter the number: ";
//     cin>>n;
//     cout<<"The table of "<<n<<" is: ";
//    for(int i=1;i<=10;i++) {
//    cout<<n*i<<" ";
//      }
// }


// #include<iostream>
// using namespace std;
// int main() {
//    int n;
//    cout<<"Enter the number of terms: ";
//    cin>>n;

//    for(int i=4;i<=3*n+1;i=i+3) {
//       cout<<i<<" ";
//    }
// }



// #include<iostream>
// using namespace std;
// int main() {
//    int n;
//    cout<<"Enter the number of terms: ";
//    cin>>n;
//    int a=3;
//    for(int i=1;i<=n;i++) {
//       cout<<a<<" ";
//       a=a*4;
//    }
// }



// #include<iostream>
// using namespace std;
// int main() {
//    int n;
//    cout<<"Enter a number: ";
//    cin>>n;

//    for(int i=n/2;i>=1;i--) {
//       if(n%i==0) {
//          cout<<i<<" ";
//          break;
//       }
//    }
// }



// #include<iostream>
// using namespace std;
// int main() {
//    int n;
//    cout<<"enter a no.: ";
//    cin>>n;
//    for(int i=2;i<=n;i++) {
//       if(n%i==0) {
//          cout<<"Composite";
//          break;
//       } else {
//          cout<<"Prime";
//          break;
//       }
//    } 
// }



// #include<iostream>
// using namespace std;
// int main() {
//    int n;
//    cout<<"enter a no.: ";
//    cin>>n;
//    bool flag=true;
//    for(int i=2;i<=n/2;i++) {
//       if(n%i==0) {
//          flag=false;
//          break;
//       }
//    } 
//    if(flag==true) cout<<"Prime";
//    else cout<<"Composite";
// }





// #include<iostream>
// using namespace std;

// int main() {
//    for(int i=1;i<=100;i++) {
//       if(i%2==0) continue;
//       cout<<i<<" ";
//    }
// }




// #include<iostream>
// using namespace std;

// int main() {
//    int x=4,y=0;
//    while(x>=0) {
//       x--;
//       y++;

//       if(x==y)
//          continue;
//       else 
//          cout<<x<<" "<<y<<endl;
//    }
// }




// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cout<<"Enter a number: ";
//    cin>>n;

//    int count=0;

//    while(n!=0) {
//       n=n/10;
//       count++;
//    }
//    cout<<count;
// }








// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cout<<"Enter a number: ";
//    cin>>n;

//    int mul=1;

//    while(n!=0) {
//       int ld=n%10;
//       n/=10;
//       mul*=ld;
//    }
//    cout<<mul;
// }






// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cout<<"Enter a number: ";
//    cin>>n;

//    int sum=0;

//    while(n!=0) {
//       int ld=n%10;
//       n/=10;
   
//       if(ld%2==0) {
//          sum+=ld;
//       }
      
//    }
//    cout<<sum;
// }
   


// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cout<<"Enter a number: ";
//    cin>>n;

//    int r=0;
//    while(n!=0) {
//       int ld=n%10;
//       r*=10;
//       r+=ld;
//       n/=10;
//    }
//    cout<<r; 
// }



// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cout<<"Enter a number: ";
//    cin>>n;

//    int sum=0;
//    int r=0;

//    while(n!=0) {
//       int ld= n%10;
//       r*=10;
//       r+=ld;
//       n/=10;
//    }
//    sum=n+r;
//    cout<<sum;
// }



// #include<iostream>
// using namespace std;

// int main() {
//    int n;
//    cout<<"Enter a number: ";
//    cin>>n;   
//    int fact=1;
//    for(int i=1;i<=n;i++) {
//       fact*=i;
//    }
//    cout<<fact;
// }






// #include<iostream>
// using namespace std;

// int fact(int x) {
//     int f=1;
//     for(int i=1;i<=x;i++) {
//         f *=i;
//     }
//     return f;
// }
// int main() {
//     int n;
//     cout<<"Enter the number: ";
//     cin>>n;
//     int r;
//     cout<<"Enter the number: ";
//     cin>>r;

//     int a= fact(n);
//     int b= fact(n-r);
//     cout<<a/b;
// }




#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++) {
        int mini=i;
        for(int j=i;j<n;j++) {
            if(arr[j]<arr[mini]) mini=j;
        }

        int temp=arr[i];
        arr[i]=arr[mini];
        arr[mini]=temp;
    }
}

void bubble_sort(int arr[],int n) {
    for(int i=n-1;i>=0;i--) {
        int didSwap=0;
        for(int j=0;j<=i-1;j++) {
            if(arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                didSwap=1;
            }
        }
        if(didSwap==0) break;
    }
}

void insertion_sort(int arr[],int n) {
    for(int i=0;i<n;i++) {
        int j=i;

        while(j>0 && arr[j-1]>arr[j]) {
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    insertion_sort(arr,n);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}