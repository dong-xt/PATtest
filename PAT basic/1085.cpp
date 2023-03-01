#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

typedef struct UNIVERSITY
{
    string name;
    double sumscore = 0;
    int amount = 0;
}UNI;

bool cmp(UNI u1, UNI u2)
{
    int sumscore_1 = u1.sumscore;
    int sumscore_2 = u2.sumscore;
    if(sumscore_1 != sumscore_2) return sumscore_1 > sumscore_2;
    else if(u1.amount != u2.amount) return u1.amount < u2.amount;
    else return u1.name.compare(u2.name) < 0;
}

string tomin(string s)
{
    string _s = s;
    for(int i = 0; i < _s.length(); i++)
    {
        if(_s[i] >= 'A' && _s[i] <= 'Z')
            _s[i] = _s[i] - 'A' + 'a';
    }
    return _s;
}

map<string, int> unidx;
map<string, int>::iterator it;

int main()
{
    int n;
    scanf("%d", &n);
    UNI un[n];
    int idx = 0;
    for(int i = 0;i < n; i++)
    {
        string s, school;
        cin >> s;
        int score;
        scanf("%d", &score);
        cin >> school;
        double _score = 0.0;
        if(s[0] == 'B') _score = (double)score / 1.5;
        else if(s[0] == 'A') _score = (double)score;
        else if(s[0] == 'T') _score = (double)score * 1.5;
        school = tomin(school);
        it = unidx.find(school);
        if(it == unidx.end())
        {
            unidx.emplace(school, idx);
            un[idx].name = school;
            un[idx].sumscore += _score;
            un[idx].amount++;
            idx++;
        }
        else
        {
            un[it->second].sumscore += _score;
            un[it->second].amount++;
        }
    }
    sort(un, un + idx, cmp);
    cout << idx << endl;
    int degree = 1;
    for(int i = 0; i < idx; i++)
    {
        if(i != 0)
        {
            int sumscore_1 = (int)(un[i].sumscore);
            int sumscore_2 = (int)(un[i-1].sumscore);
            if(sumscore_1 != sumscore_2)
            {
                degree = i + 1;
            }
        }
        cout << degree << " " << un[i].name << " " << (int)(un[i].sumscore) << " " << un[i].amount << endl;
    }
    return 0;
}
