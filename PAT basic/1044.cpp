#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    const string num_l[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                              "jly", "aug", "sep", "oct", "nov", "dec"};
    const string num_h[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", 
                              "hei", "elo", "syy", "lok", "mer", "jou"};
    int n;
    int i10 = 0, i13 = 0;
    string in, s13 = "";
	getline(cin, in);
	n = stoi(in);
    for(int i = 0; i < n; i++)
    {
        i13 = 0; s13 = "";
        getline(cin, in);
        if(in[0] >= '0' && in[0] <= '9')
        {
            i10 = stoi(in);
            if(i10 % 13 == 0 && i10 != 0)       //可能只有一位高位
                s13 = num_h[i10 / 13];
            else
            {
                s13 = num_l[i10 % 13] + s13;
                i10 /= 13;
                if(i10 != 0)
                    s13 = num_h[i10 % 13] + " " + s13;                
            }
            cout << s13 << endl;
        }
        else
        {
            if(in.find(' ') != string::npos)
            {
                int pos = in.find(' ');
                string s1 = in.substr(0, pos);
                string s2 = in.substr(pos + 1, in.length() - pos - 1);
                for(int i = 0; i < 13; i++)
                {
                    if(s1.compare(num_h[i]) == 0)
                        i13 += i * 13;
                    if(s2.compare(num_l[i]) == 0)
                        i13 += i;
                }
                cout << i13 << endl;
            }
            else
            {
                for(int i = 0; i < 13; i++)
                {
                    if(in.compare(num_l[i]) == 0)
                    {
                        i13 = i;
                        break;                        
                    }
                    if(in.compare(num_h[i]) == 0)
                    {
                        i13 = i * 13;
                        break;                        
                    }
                }
                cout << i13 << endl;
            }
        }
    }
    return 0;
}
