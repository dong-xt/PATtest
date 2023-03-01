#include <iostream>
#include <cmath>

using namespace std;

bool check_prime(int n)
{
    bool result = true;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            result = false;
            break;            
        }
    }
    return result;
}

int main()
{
    int N;
    cin >> N;
    int pn = 2;
    int pnp1 = 3;
    int cnt = 0;
    for(int i = 4; i <= N; i++)
    {
        if(check_prime(i))
        {
            pn = pnp1;
            pnp1 = i;
            if(pnp1 - pn == 2)
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
