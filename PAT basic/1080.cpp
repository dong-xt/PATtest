#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

struct STU
{
    string id;
    int gp = 0;
    int gmt = -1;
    int gf = -1;
    int g = -1;
};

bool cmp(STU s1, STU s2)
{
    if(s1.g != s2.g) return s1.g > s2.g;
    else return s1.id < s2.id;
}

map<string, int> mymap;
map<string, int>::iterator it;

int main()
{
    int p, m, n;
    cin >> p >> m >> n;
    int cnt = 0;
    STU stu[p];
    string dir[p];
    
    for(int i = 0; i < p; i++)
    {
        string id;
        int gp;
        cin >> id;
        scanf("%d",&gp);
        if(gp >= 200 && gp <= 900)
        {
            stu[cnt].id = id;
            stu[cnt].gp = gp;
            mymap.emplace(id, cnt);            
            cnt++;
        }
    }
    for(int i = 0; i < m; i++)
    {
        string id;
        int gmt;
        cin >> id;
        scanf("%d",&gmt);
//         int pos = search(id, stu, cnt);
        it = mymap.find(id);
        if(it != mymap.end()) stu[it->second].gmt = gmt;
    }
    for(int i = 0; i < n; i++)
    {
        string id;
        int gf;
        cin >> id;
        scanf("%d",&gf);
        it = mymap.find(id);
        if(it != mymap.end())
        {
            stu[it->second].gf = gf;
            if(stu[it->second].gmt > stu[it->second].gf)
                stu[it->second].g = 0.4 * (float)stu[it->second].gmt + 0.6 * (float)stu[it->second].gf + 0.5;
            else
                stu[it->second].g = stu[it->second].gf;            
        }
    }
    sort(stu, stu + cnt, cmp);
    for(int i = 0; i < cnt; i++)
    {
        if(stu[i].g != -1 && stu[i].g >= 60)
        {
            cout << stu[i].id;
            printf(" %d %d %d %d\n", stu[i].gp, stu[i].gmt, stu[i].gf, stu[i].g);
        }
        else
            break;
    }
    return 0;
}
