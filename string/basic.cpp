#include <bits/stdc++.h> 
#include<cmath>
using namespace std;

int main() {
    int basic,allow;
    cin >> basic;

    char grade;
    cin >> grade;

    double hra,da,pf;

    hra = (20*basic) / 100;
    da = (50*basic) / 100;
    pf = (11*basic) / 100;

    if(grade == 'A') allow = 1700;
    else if(grade == 'B') allow = 1500;
    else allow = 1300;

    double totalSalary;

    totalSalary = basic + hra + da + allow - pf;

    cout << round(totalSalary);  

    return 0;
}