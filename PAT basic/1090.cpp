#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string, string> errmap;
map<string, string>::iterator it;
map<string, bool> stuff;
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        it = errmap.find(a);
        if(it != errmap.end()) it->second += b;
        else errmap.emplace(a, b);
        it = errmap.find(b);
        if(it != errmap.end()) it->second += a;
        else errmap.emplace(b, a);       
    }
    for(int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        stuff.clear();
        bool find = false;
        for(int j = 0; j < num; j++)
        {
            string test;
            cin >> test;
            it = errmap.find(test);
            if(it != errmap.end() && !find)
            {
                string s = it->second;
                for(int k = 0; k < s.length(); k += 5)
                {
                    string _s = s.substr(k, 5);
                    if(stuff.find(_s) != stuff.end())
                    {
                        cout << "No" << endl;
                        find = true;
                        break;
                    }
                }
            }
            stuff.emplace(test, true);
        }
        if(!find) cout << "Yes" << endl;
    }
    return 0;
}
