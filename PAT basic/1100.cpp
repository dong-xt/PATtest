#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, bool> mymap;
map<string, bool>::iterator it;

int main()
{
    int n;
    cin >> n;
    string g_old = string(18, '9'), s_old = string(18, '9'); 
    for(int i = 0; i < n; i++)
    {
        string id;
        cin >> id;
        mymap.emplace(id, true);
    }
    int m;
    cin >> m;
    int scnt = 0;
    for(int i = 0; i < m; i++)
    {
        string id;
        cin >> id;
        it = mymap.find(id);
        if(it != mymap.end())
        {
            scnt++;
            if(id.substr(6, 8) < s_old.substr(6, 8))  
                s_old = id;            
        }
        else if(scnt == 0)
        {
            if(id.substr(6, 8) < g_old.substr(6, 8))
                g_old = id;            
        }
    }
    cout << scnt << endl;
    if(scnt == 0) cout << g_old << endl;
    else cout << s_old << endl;
    return 0;
}
