#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct QUEST
{
    int grade;
    string ans = "";
};

struct ERROR
{
    int times = 0;
    int id;
    char choice;
};

bool cmp(ERROR e1, ERROR e2)
{
    if(e1.times != e2.times) return e1.times > e2.times;
    else if(e1.id != e2.id) return e1.id < e2.id;
    else return e1.choice < e2.choice;
}

int main()
{
    int n, m;
    cin >> n >> m;
    QUEST qs[m];
    for(int i = 0; i < m; i++)
    {
        int total, correct;
        cin >> qs[i].grade;
        cin >> total >> correct;
        for(int j = 0; j < correct; j++)
        {
            string choice;
            cin >> choice;
            qs[i].ans += choice;
        }
    }
    
    ERROR e[5 * m];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            e[i * 5 + j].id = i + 1;
            e[i * 5 + j].choice = 'a' + j;
        }
    }
    for(int i = 0; i < n; i++)
    {
        float grade = 0;
        for(int j = 0; j < m; j++)
        {
            string reply = "";
            while(1)
            {
                string s;
                cin >> s;
                if(s[0] >= 'a' && s[0] <= 'e')
                    reply += s[0];
                if(s.length() == 2 && s[1] == ')')
                    break;
            }
            bool contain = true; 
            for(int k = 0; k < reply.length(); k++)
            {
                if(qs[j].ans.find(reply[k]) == string::npos)
                {
                    e[(int)(j * 5 + reply[k] - 'a')].times++;
                    contain = false;
                }
            }            
            if(contain)
            {
                if(qs[j].ans == reply)
                    grade += qs[j].grade;
                else
                {
                	grade += (float)(qs[j].grade) / 2;                   	
				}
            }
            for(int k = 0; k < qs[j].ans.length(); k++)
            {
                if(reply.find(qs[j].ans[k]) == string::npos)
                {
                    e[(int)(j * 5 + qs[j].ans[k] - 'a')].times++;
                }
            } 			            
        }
        printf("%.1f\n", grade);
    }
    sort(e, e + 5 * m, cmp);
    if(e[0].times == 0)
    {
        cout << "Too simple" << endl;
    }
    else
    {
        cout << e[0].times << " " << e[0].id << "-" << e[0].choice << endl;
        for(int i = 1; i < 5 * m; i++)
        {
            if(e[i].times == e[i-1].times)
                cout << e[i].times << " " << e[i].id << "-" << e[i].choice << endl;
            else
                break;
        }        
    }

    
    return 0;
}
