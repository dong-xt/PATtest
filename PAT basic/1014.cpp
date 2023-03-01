#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string a1, a2;
    string b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int l1 = min<int>(a1.length(), a2.length());
    int l2 = min<int>(b1.length(), b2.length());
    int t1 = 0;
    string day; int hour; int minute;
    for(int i = 0; i < l1; i++)
    {
        char c1 = a1[i];
        char c2 = a2[i];
        if(t1 == 0 && c1 == c2 && c1 >= 'A' && c1 <= 'G')
        {
            switch(c1)
            {
                case 'A': day = "MON";break;
                case 'B': day = "TUE";break;
                case 'C': day = "WED";break;
                case 'D': day = "THU";break;
                case 'E': day = "FRI";break;
                case 'F': day = "SAT";break;
                case 'G': day = "SUN";break;
            }
            t1 = 1; continue;
        }
        else if(t1 == 1 && c1 == c2)
        {
            if(c1 >= '0' && c1 <= '9')
            {
                hour = c1 - '0'; break;                
            }
            else if(c1 >= 'A' && c1 <= 'N')
            {
                hour = c1 - 'A' + 10; break;                
            }
        }
    }
    for(int j = 0; j < l2; j++)
    {
        char d1 = b1[j];
        char d2 = b2[j];
        if((d1 >= 'a' && d1 <='z') || (d1 >= 'A' && d1 <='Z'))
        {
            if(d1 == d2)
            {
                minute = j; break;                
            }
        }
    }
    cout << day << " ";
    if(hour < 10)
        cout << "0" << hour << ":";
    else
        cout << hour << ":";
    if(minute < 10) 
        cout << "0" << minute;
    else 
        cout << minute;
    return 0;
}
