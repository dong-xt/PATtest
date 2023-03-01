#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<map>
using namespace std;

struct STUDENT
{
    string id;
    int grade;
};

struct ROOM
{
    int num = 0;
    int sumgrade = 0;
};

struct DAY
{
    string date;
    int rmidx;
    int num = 0;
};

bool stu_cmp(STUDENT s1, STUDENT s2)
{
    if(s1.grade != s2.grade) return s1.grade > s2.grade;
    else return s1.id < s2.id;
}

bool dy_cmp(DAY d1, DAY d2)
{
    if(d1.date != d2.date) return d1.date < d2.date;
    else if(d1.num != d2.num) return d1.num > d2.num;
    else return d1.rmidx < d2.rmidx;
}

map<string, int> drmap;
map<string, int>::iterator it;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    STUDENT stub[n], stua[n], stut[n];
    int bcnt = 0, acnt = 0, tcnt = 0;
    ROOM rm[1000];
    DAY dy[n];
    int dy_cnt = 0;
    
    for(int i = 0; i < n; i++)
    {
        string id; cin >> id;
        int grade = 0; scanf("%d", &grade);
        if(id[0] == 'B')
        {
            stub[bcnt].id = id; stub[bcnt].grade = grade;
            bcnt++;
        }
        else if(id[0] == 'A')
        {
            stua[acnt].id = id; stua[acnt].grade = grade;
            acnt++;
        }
        else if(id[0] == 'T')
        {
            stut[tcnt].id = id; stut[tcnt].grade = grade;
            tcnt++;
        }
        string _rmid = id.substr(1, 3);
        int rmid = stoi(_rmid);
        rm[rmid].num++;
        rm[rmid].sumgrade += grade;
        string date = id.substr(4, 6);
        drmap.emplace(date, 0);
        string dateroom = date + _rmid;
        it = drmap.find(dateroom);
        if(it != drmap.end())
        {
            dy[it->second].num++;
        }
        else
        {
            dy[dy_cnt].date = date;
            dy[dy_cnt].rmidx = rmid;
            dy[dy_cnt].num++;
            drmap.emplace(dateroom, dy_cnt);
            dy_cnt++;
        }
    }
    
    for(int i = 0; i < m; i++)
    {
        int type = 0; scanf("%d", &type);
        string s; cin >> s;
        printf("Case %d: %d ", i+1, type);
        cout << s << endl;
        if(type == 1)
        {
            if(s == "B")
            {
                if(bcnt == 0) printf("NA\n");
                else
                {
                    sort(stub, stub + bcnt, stu_cmp);
                    for(int j = 0; j < bcnt; j++)
                    {
                        cout << stub[j].id;
                        printf(" %d\n", stub[j].grade);
                    }
                }
            }
            else if(s == "A")
            {
                if(acnt == 0) printf("NA\n");
                else
                {
                    sort(stua, stua + acnt, stu_cmp);
                    for(int j = 0; j < acnt; j++)
                    {
                        cout << stua[j].id;
                        printf(" %d\n", stua[j].grade);
                    }
                }
            }
            else 
            {
                if(tcnt == 0) printf("NA\n");
                else
                {
                    sort(stut, stut + tcnt, stu_cmp);
                    for(int j = 0; j < tcnt; j++)
                    {
                        cout << stut[j].id;
                        printf(" %d\n", stut[j].grade);
                    }
                }                
            }
        }
        else if(type == 2)
        {
            int idx = stoi(s);
            if(rm[idx].num != 0) 
            {
                printf("%d %d\n", rm[idx].num, rm[idx].sumgrade);
            }
            else printf("NA\n");
        }
        else if(type == 3)
        {
            it = drmap.find(s);
            if(it == drmap.end()) printf("NA\n");
            else
            {
                sort(dy, dy+dy_cnt, dy_cmp);
                bool find = false;
                for(int j = 0; j < dy_cnt; j++)
                {
                    if(dy[j].date == s)
                    {
                        find = true;
                        printf("%d %d\n", dy[j].rmidx, dy[j].num);
                    }
                    else if(find)
                        break;
                }
            }
        }
    }
    
    return 0;
}
