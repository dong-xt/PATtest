#include<iostream>
#include<string>
using namespace std;

int main()
{
    string english[26][7];
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            cin >> english[i][j];
        }        
    }
    int seq[10];
    int cnt = 0;
    cin.ignore(10, '\n');
    string s;
    getline(cin, s);
    int begin, end;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            begin = i; break;
        }
    }
    for(int i = s.length() - 1; i >=0 ; i--)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            end = i; break;
        }
    }    
    s = s.substr(begin, end - begin + 1);
    bool wait = false;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] < 'A' || s[i] > 'Z' || i == s.length() - 1)
        {
            if(i == s.length() - 1)
            {
                int idx = s[i] - 'A';
                seq[cnt] = idx;
                cnt++; 
                wait = true;
            }            
        	if(wait)
        	{
	            for(int j = 0; j < 7; j++)
	            {
	                for(int k = 0; k < cnt; k++)
	                {
	                    cout << english[seq[k]][j];
	                    if(k == cnt - 1 && j != 6) cout << endl;
	                    else if(k != cnt - 1) cout << " ";
	                }
	            }
	            if(i != s.length() - 1)
	            {
	                cout << endl;
	                cout << endl;
	                cnt = 0;
	                wait = false;
	            }        		
			}
        }
        else
        {
            wait = true;
            int idx = s[i] - 'A';
            seq[cnt] = idx;
            cnt++;
        }
    }

    return 0;
}
