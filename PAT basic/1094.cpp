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
            if(a % i == 0)
                return false;
        }        
    }
    return true;
}

int main()
{
    int l, k;
    cin >> l >> k;
    string n;
    cin >> n;
    for(int i = 0; i <= l - k; i++)
    {
        string _n = n.substr(i, k);
        long long check = stoll(_n);
        if(isprime(check))
        {
            cout << _n;
            return 0;
        }
    }
    cout << "404";
    return 0;
}
