#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s, s_gold;
    cin >> s >> s_gold;
    int l = s_gold.length();
    int cnt = 0;
    for(int i = 0; i < l; i++)
    {
        if(s.find(s_gold[i]) == string::npos)
            cnt++;
        else
        {
        	unsigned int pos = s.find(s_gold[i]);
        	s.erase(pos, 1);
		}
    }
    if(cnt == 0)
        cout << "Yes " << s.length() << endl;
    else
        cout << "No " << cnt << endl;
    return 0;
}
