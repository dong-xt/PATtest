#include<iostream>
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
        return true;
    }
}

int main()
{
    long long n;
    cin >> n;
    bool check = true;
    if(isprime(n))
    {
        if(isprime(n-6))
        {
            cout << "Yes" << endl;
            cout << n - 6 << endl;
        }
        else if(isprime(n + 6))
        {
            cout << "Yes" << endl;
            cout << n + 6 << endl;
        }
        else
            check = false;
    }
    else
        check = false;
    while(!check)
    {
        n++;
        if(isprime(n) && (isprime(n-6) || isprime(n + 6)))
        {
            cout << "No" << endl;
            cout << n << endl;
            check = true;
        }
    }
    
    return 0;
}
