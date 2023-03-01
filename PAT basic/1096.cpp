#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int num;
        cin >> num;
        int factor[num];
        int cnt = 0;
        for(int j = 1; j <= sqrt(num); j++)
        {
            if(num % j == 0)
            {
                factor[cnt] = j; cnt++;
                if(num / j != j)
                {
                    factor[cnt] = num / j;
                    cnt++;
                }
            }
        }
        bool find = false;
        for(int a = 0; a < cnt; a++)
        {
            for(int b = a + 1; b < cnt; b++)
            {
                for(int c = b + 1; c < cnt; c++)
                {
                    for(int d = c + 1; d < cnt; d++)
                    {
                        int sum = factor[a] + factor[b] + factor[c] + factor[d];
                        if(sum % num == 0)  //a Õû³ý b --> b%a==0
                        {
                            cout << "Yes" << endl;
                            find = true;
                            break;
                        }
                    }
                    if(find) break;
                }
                if(find) break;
            }
            if(find) break;
        }
        if(!find) cout << "No" << endl;
    }
    return 0;
}
