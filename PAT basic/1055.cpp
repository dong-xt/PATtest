#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct MSG
{
    string name;
    int h;
};

bool cmp(MSG a, MSG b)
{
    if(a.h != b.h)
        return a.h > b.h;
    else
        return a.name < b.name; //compare -1 0 1 bool true false 只要不相等就返回真
}

int main()
{
    int n, k;
    cin >> n >> k;
    MSG p[n];
    for(int i = 0; i < n; i++)
        cin >> p[i].name >> p[i].h;
    sort(p, p + n, cmp);
//      for(int i = 0; i < n; i++)
//          cout << p[i].name << " ";
//      cout << endl;
    int m = n / k;
    int endm = (n % k == 0) ? n / k : n - (k - 1) * m;
    int middle = m / 2;
    int endmiddle = endm / 2;
    string _ep[endm];
    _ep[endmiddle] = p[0].name;
    int i = endmiddle - 1, j = endmiddle + 1;
    int idx = 1;
    while((i >= 0 || j <= endm - 1) && idx <= n-1 )
    {
        if(i >= 0)
        {
            _ep[i] = p[idx].name;
            i--; idx++;
        }
        if(j <= endm - 1)
        {
            _ep[j] = p[idx].name;
            j++; idx++;
        }
    }
    for(int a = 0; a < endm; a++)
        if(a == endm - 1)
            cout << _ep[a] << endl;
        else
            cout << _ep[a] << " ";
    for(int a = 0; a < k - 1; a++)
    {
        string _p[m];
        _p[middle] = p[idx].name;
        idx++; 
        i = middle - 1; j = middle + 1;
        while(i >= 0 || j <= m - 1)
        {
            if(i >= 0)
            {
                _p[i] = p[idx].name;
                i--; idx++;
            }
            if(j <= m - 1)
            {
                _p[j] = p[idx].name;
                j++; idx++;
            }
        }
        for(int b = 0; b < m; b++)
            if(b == m - 1)
                cout << _p[b] << endl;
            else
                cout << _p[b] << " ";        
    }
    
    return 0;
}
