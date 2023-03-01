#include<iostream>
#include<algorithm>
using namespace std;

struct STUDENT
{
    int id;
    int dpoint;
    int ipoint;
    int points;
};

//自定义排序规则
//s1.points > s2.points 降序 s1.points < s2.points 升序 
bool cmp(STUDENT s1, STUDENT s2)
{
    if(s1.points != s2.points)
        return s1.points > s2.points;
    else if(s1.dpoint != s2.dpoint)
        return s1.dpoint > s2.dpoint;
    else
        return s1.id < s2.id;
}

int main()
{
    int N, L, H;
    cin >> N >> L >> H;
    STUDENT s1[N], s2[N], s3[N], s4[N];
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for(int i = 0; i < N ; i++)
    {
        STUDENT _s;
        cin >> _s.id >> _s.dpoint >> _s.ipoint;
        _s.points = _s.dpoint + _s.ipoint;
        if(_s.dpoint >= L && _s.ipoint >= L)
        {
            if(_s.dpoint >= H && _s.ipoint >= H)
            {
                s1[cnt1] = _s;
                cnt1++;
            }
            else if(_s.dpoint >= H && _s.ipoint < H)
            {
                s2[cnt2] = _s;
                cnt2++;
            }
            else if(_s.dpoint < H && _s.ipoint < H && _s.dpoint >= _s.ipoint)
            {
                s3[cnt3] = _s;
                cnt3++;
            }
            else
            {
                s4[cnt4] = _s;
                cnt4++;
            }
        }
    }
    sort(s1, s1 + cnt1, cmp);//利用STL的sort()快排
    sort(s2, s2 + cnt2, cmp);
    sort(s3, s3 + cnt3, cmp);
    sort(s4, s4 + cnt4, cmp);
    cout << cnt1 + cnt2 + cnt3 + cnt4 << endl;
    for(int i = 0; i < cnt1; i++)
        cout << s1[i].id << " " << s1[i].dpoint << " " << s1[i].ipoint << endl;
    for(int i = 0; i < cnt2; i++)
        cout << s2[i].id << " " << s2[i].dpoint << " " << s2[i].ipoint << endl;
    for(int i = 0; i < cnt3; i++)
        cout << s3[i].id << " " << s3[i].dpoint << " " << s3[i].ipoint << endl;
    for(int i = 0; i < cnt4; i++)
        cout << s4[i].id << " " << s4[i].dpoint << " " << s4[i].ipoint << endl;
    
    return 0;
}
