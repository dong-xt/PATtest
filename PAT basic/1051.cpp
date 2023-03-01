#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

int main()
{
    double r1, p1, r2, p2;
    cin >> r1 >> p1 >> r2 >> p2;
    double a1 = r1 * cos(p1);
    double b1 = r1 * sin(p1);
    double a2 = r2 * cos(p2);
    double b2 = r2 * sin(p2);
//     cout << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
    double a = a1 * a2 - b1 * b2;
    double b = a1 * b2 + a2 * b1;
//     cout << a << " " << b << endl;
    if(a > -0.005 && a < 0) cout << "0.00";     //-0.002 »áÊä³ö -0.00
    else printf("%.2f", a);
    if(b > -0.005 && b <= 0) cout << "+0.00";
    else if(b <= -0.005) printf("-%.2f", -1 * b);
    else printf("+%.2f", b);
    cout << "i" << endl;
    
    return 0;
}
