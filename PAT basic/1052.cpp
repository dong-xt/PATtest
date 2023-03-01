#include<iostream>
#include<string>
using namespace std;

int extract(string s, string c[], int n)
{
   int index = -1, cnt = 0;
   for(int i = 0; i < s.length(); i++)
   {
       if(s[i] == '[')
           index = i;
       else if(s[i] == ']' && index != -1)
       {
           c[cnt++] = s.substr(index + 1, i - 1 - index);
           index = -1;
       }
   }
   return cnt;
}

int main()
{
    string s;
    string hand[10];
    string eye[10];
    string mouth[10];
    int h_cnt = 0, e_cnt = 0, m_cnt = 0;
    getline(cin, s); h_cnt = extract(s, hand, 10);
    getline(cin, s); e_cnt = extract(s, eye, 10);
    getline(cin, s); m_cnt = extract(s, mouth, 10);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int pos;
        string out = "";
        for(int j = 0; j < 5; j++)
        {
            cin >> pos;
            if(j == 0 || j == 4) //hand
            {
                if(pos < 1 || pos > h_cnt)  //pos有可能为0或负数
                {
                    out = "Are you kidding me? @\\/@"; break;
                }
                else 
                    out+= hand[pos - 1];
            }
            else if(j == 1 || j == 3)
            {
                if(j == 1) out += '(';
                if(pos < 1 || pos > e_cnt)
                {
                    out = "Are you kidding me? @\\/@"; break;                 
                }
                else
                    out += eye[pos - 1];
                if(j == 3) out += ')'; 
            }
            else
            {
                if(pos < 1 || pos > m_cnt)
                {
                    out = "Are you kidding me? @\\/@"; break;                  
                }
                else
                    out += mouth[pos - 1];                
            }
        }
        cout << out << endl;
    }
    
    return 0;
}
