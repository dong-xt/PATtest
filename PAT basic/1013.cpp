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
    int index = 0;
    int m, n;
    cin >> m >> n;
    int i = 2;
    int cnt = 0;
    while(index < n)
    {        
        if(check_prime(i))
        {
            index++;
            if(index >= m && index <= n)
            {
                cnt++;
                cout << i;
                if(cnt != 10 && index != n) cout << " ";
                else{
                    cout << endl;
                    cnt = 0;
                }
            }
        }
        i++;
    }
    return 0;
}
