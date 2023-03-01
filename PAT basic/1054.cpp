#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

bool islegal(string s)
{
    bool res = true;
    bool hadpoint = false;
    int pointend = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '-')
        {
        	if(i != 0)
        	{
	            res = false;
	            break;         		
			}           
        }
        else if(s[i] == '.')
        {
            if(hadpoint)
            {
                res = false;
                break;
            }
            else 
                hadpoint = true;
        }
        else if(s[i] < '0' || s[i] > '9')
        {
            res = false;
            break;            
        }
        else
        {
            if(hadpoint) pointend++;
        }
    }
    if(hadpoint && pointend > 2) //形如 12. 这样的也是正确的 尽管我看起来不正确
        res = false;
    return res;
}

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    float sum = 0.0;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if(!islegal(s))
        {
            cout << "ERROR: " << s << " is not a legal number" << endl;
        }
        else
        {
            float num = stof(s);
            if(num < -1000 || num > 1000)
                cout << "ERROR: " << s << " is not a legal number" << endl;
            else
            {
                cnt++;
                sum += num;
            }
        }
    }
    if(cnt == 0)
        cout << "The average of 0 numbers is Undefined" << endl;
    else if(cnt == 1)
    {
        cout << "The average of 1 number is ";
        printf("%.2f\n",sum);
    }
    else
    {
        float aver = sum / cnt;
        cout<< "The average of " << cnt << " numbers is ";
        printf("%.2f\n",aver);
    }
    return 0;
}
