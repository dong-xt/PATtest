#include<iostream>
// #include<string>
// #include<algorithm>
#include<cmath>
using namespace std;

long long gcd(long long t1, long long t2)   //�����Լ��
{
    return t2 == 0 ? t1 : gcd(t2, t1 % t2);
}

void func(long long m, long long n) //������������ʽ
{
    if(m == 0 || n == 0)    //���ӷ�ĸΪ0���⴦��
    {
        n == 0 ? (cout << "Inf") : (cout << "0");
        return;
    }
    bool flag = true;
    if((m < 0 && n > 0) || (m > 0 && n < 0))    //�������
        flag = false;
    m = llabs(m); n = llabs(n);
    flag ? (cout << "") : (cout << "(-");
    long long div = m / n;      //ת���������ʽ
    if(div != 0) cout << div;
    if(m % n != 0)
    {
        m = m - div * n;
        if(div != 0) cout << " ";
        long long x = gcd(m, n);    //����
        m /= x;
        n /= x;
        cout << m << "/" << n;
    }
    flag ? (cout << "") : (cout << ")");
}

int main()
{
    long long a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    func(a, b); cout<< " + "; func(c, d); cout << " = "; func(a * d + b * c, b * d); cout << endl;
    func(a, b); cout<< " - "; func(c, d); cout << " = "; func(a * d - b * c, b * d); cout << endl;
    func(a, b); cout<< " * "; func(c, d); cout << " = "; func(a * c, b * d); cout << endl;
    func(a, b); cout<< " / "; func(c, d); cout << " = "; func(a * d, b * c); cout << endl;

    return 0;
}
