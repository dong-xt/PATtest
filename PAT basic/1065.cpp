#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int marry[100000];
    fill(marry, marry + 100000, -1);
    for(int i = 0; i < n; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        marry[c1] = c2;
        marry[c2] = c1;
    }
    int m;
    cin >> m;
    int sdog[m], s[m];
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < m; i++)
    {
        int g;
        cin >> g;
        if(marry[g] == -1)
        {
            sdog[cnt1] = g;
            cnt1++;
        }
        else
        {
            int another = marry[g];
            bool find = false;
            for(int j = 0; j < cnt2; j++)
            {
                if(s[j] == another)
                {
                    s[j] = -1;
                    find = true;
                    break;
                }
            }
            if(!find)
            {
                s[cnt2] = g;
                cnt2++;
            }
        }
    }
    for(int i = 0; i < cnt2; i++)
    {
        if(s[i] != -1)
        {
            sdog[cnt1] = s[i];
            cnt1++;            
        }
    }
    sort(sdog, sdog + cnt1);
    cout << cnt1 << endl;
    for(int i = 0; i < cnt1; i++)
    {
        cout << setw(5) << setfill('0') << sdog[i];     //位宽为5
        if(i != cnt1 - 1) cout << " ";
        else cout << endl;      //放在这里是 如果为0 不进行多换行输出
    }
    return 0;
}
