#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

long long gcd(long long t1, long long t2)   //求最大公约数
{
    return t2 == 0 ? t1 : gcd(t2, t1 % t2);
}

int strsum(long long a)
{
    string s = to_string(a);
    int sum = 0;
    for(int i = 0; i < s.length(); i++)
        sum += (s[i] - '0');
    return sum;
}

bool isprime(long long n)
{
    for(long long i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}

struct RESULT
{
    int n;
    long long A;
};

bool cmp(RESULT r1, RESULT r2)
{
    if(r1.n != r2.n) return r1.n < r2.n;
    else return r1.A < r2.A;
}
RESULT rs[10000000];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int k, m;
        cin >> k >> m;
        string _min = "1" + string(k-1, '0');
        string _max = string(k, '9');
        long long min = stoll(_min);
        long long max = stoll(_max);
        cout << "Case " << i + 1 << endl;
        long long cnt = 0;
        for(long long j = min + 99; j <= max; j+=100)
        {
            int sj = strsum(j);
            int sj1 = strsum(j+1);
            if(sj == m)
            {
                long long common = gcd(sj, sj1);
                if(common > 2 && isprime(common))
                {
                    rs[cnt].n = sj1; rs[cnt].A = j;
                    cnt++;
                }
            }
        }
        if(cnt==0) cout << "No Solution" << endl;
        else
        {
            sort(rs, rs+cnt, cmp);
            for(int j = 0;j < cnt; j++)
                cout << rs[j].n << " " << rs[j].A << endl;
        }
    }
    return 0;
}
