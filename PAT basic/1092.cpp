#include<iostream>
#include<algorithm>
using namespace std;

struct CAKE
{
    int id;
    long cnt = 0;
};

bool cmp(CAKE c1, CAKE c2)
{
    if(c1.cnt != c2.cnt) return c1.cnt > c2.cnt;
    else return c1.id < c2.id;
}

int main()
{
    int n, m;
    cin >> n >> m;
    CAKE cake[n];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            if(i == 0) cake[j].id = j + 1;
            cake[j].cnt += num;
        }
    }
    sort(cake, cake + n, cmp);
    cout << cake[0].cnt << endl;
    for(int i = 0; i < n; i++)
    {
        if(cake[i].cnt == cake[0].cnt)
        {
            if(i != 0) cout << " ";
            cout << cake[i].id;            
        }
        else
            break;
    }
    cout << endl;
    return 0;
}
