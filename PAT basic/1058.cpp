#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

struct TOPIC
{
    int score;
    int ans;
};

struct ERROR
{
    int id;
    int times = 0;
};

bool cmp(ERROR e1, ERROR e2)
{
    if(e1.times != e2.times) return e1.times > e2.times;
    else return e1.id < e2.id;
}

int main()
{
    int n, m;
    cin >> n >> m;
    TOPIC t[m];
    ERROR e[m];
    for(int i = 0; i < m; i++) e[i].id = i + 1;
    string s;
    cin.ignore(10, '\n');
    for(int i = 0; i < m; i++)
    {
        cin >> t[i].score;
        int temp;
        cin >> temp;
        cin >> temp;
        int _ans = 0;
        for(int j = 0; j < temp; j++)
        {
            char c_ans;
            cin >> c_ans;
            _ans = _ans + pow(10, (int)(c_ans - 'a'));
        }
        t[i].ans = _ans;
    }
    cin.ignore(10, '\n');
    for(int i = 0; i < n; i++)
    {
        getline(cin, s);
        int id = 0;
        int leftidx = 0;
        int sumscore = 0;
        for(int j = 0; j < s.length(); j++)
        {
            string s_ans;
            int ansp = 0;
            if(s[j] == '(')
                leftidx = j + 1;
            else if(s[j] == ')')
            {
                s_ans = s.substr(leftidx, j - leftidx);
                for(int k = 0; k < s_ans.length(); k++)
                {
                    if(s_ans[k]!= ' ')
                        ansp = ansp + pow(10, (int)(s_ans[k] - 'a')); 
                }
//                 cout << ansp << endl;
                if(t[id].ans == ansp)
                {
                    sumscore = sumscore + t[id].score;
					id++;                	
				}
                else
                {
                    e[id].times++;
					id++;                	
				}
            }                
        }
        cout << sumscore << endl;
    }
    sort(e, e + m, cmp);
    if(e[0].times == 0)
        cout << "Too simple" << endl;
    else
    {
        cout << e[0].times << " " << e[0].id;
        for(int i = 1; i < m; i++)
        {
            if(e[i].times == e[0].times)
            {
                cout << " " << e[i].id;
            }
            else 
                break;
        }
        cout << endl;
    }
    return 0;
}
