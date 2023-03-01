#include <iostream>
#include <string>
using namespace std;

bool all_A(string _s_sub)
{
	if(_s_sub != "")
	{
		for(int i = 0; i < _s_sub.length(); i++)
		{
			if(_s_sub[i] != 'A')
			{
				return false;
			}
		}	
	}
	return true;
}

bool check(string _s)
{
	int p_index, t_index;
	int l = _s.length();
	if(((p_index = _s.find('P')) != string::npos) && ((t_index = _s.find('T')) != string::npos)
	 		&& (t_index - p_index > 1))
	{
		int l1 = p_index;
		int l2 = t_index - p_index - 1;
		int l3 = l - t_index - 1;
		if(all_A(_s.substr(0, l1)) && all_A(_s.substr(p_index + 1, l2)) && all_A(_s.substr(t_index + 1, l3)) 
		&& (l1 * l2 == l3))
		{
			return true;
		}
	}
	return false;	
} 

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s = "";
        cin >> s;
        if(check(s))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
