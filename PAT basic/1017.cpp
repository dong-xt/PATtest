#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a;
    int b;
    cin >> a >> b;
    int i = 0;
    int l = a.length();
    string q = "";
    int r = 0;
    int part = a[i] - '0';
    bool flag = false;  //�ж��̲�0�ı�־λ
    while(i < l)
    {
        int _q;
        if(part >= b) 
        {
            _q = part / b;
            part = part % b;
            q += to_string(_q);
            flag = false;
        }
        else if(part < b && flag)
        {
            _q = 0;
            q += to_string(_q);
            flag = false;
        }
        else if(part < b && i != l - 1)
        {
            i++;
            part = part * 10 + a[i] - '0';
            flag = true;
        }
        else if(part < b && i == l - 1)
        {
            r = part; i++;
        }
    }
    if(q == "")         //һλ����һλ�� ��Ϊ0�����
        q = "0";
    cout << q << " " << r << endl;
    
    return 0;
}
