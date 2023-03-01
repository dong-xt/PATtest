#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool isprime(long long a)
{
    if(a <= 1)
        return false;
    else
    {
        for(long long i = 2; i <= sqrt(a); i++)
        {
            if(a % i == 0) return false;
        }
        return true;
    }
}

int main()
{
    string date;
    cin >> date;
    long long _date = stoll(date);
    int l = date.length();
    bool allprime = true;
    long long div = 10000000;
    for(int i = 0; i < l; i++)
    {
        if(isprime(_date)) 
        {
			cout << date << " Yes" << endl;        	
		}
        else
        {	
            cout << date << " No" << endl;
            allprime = false;
        }
        date.erase(0, 1);
        _date %= div;
        div /= 10;
    }
    if(allprime) cout << "All Prime!" << endl;
    return 0;
}
