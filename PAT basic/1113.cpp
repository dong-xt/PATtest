#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	const char _num30[31] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
							'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
                            'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'};
    string a, b;
    cin >> a >> b;
    int la = a.length(), lb = b.length();
    int l = la;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());    
    if(la > lb)
	{
		b += string(la - lb, '0');
		l = la;
	} 
    else if(lb > la)
	{
		a += string(lb - la, '0');
		l = lb;	
	} 
    int advance = 0;
    string s = "";
    for(int i = 0; i < l; i++)
    {
    	int value_a, value_b;
        if(a[i] >= '0' && a[i] <= '9') value_a = a[i]-'0';
        else value_a = a[i] - 'a' + 10;
        if(b[i] >= '0' && b[i] <= '9') value_b = b[i]-'0';
        else value_b = b[i] - 'a' + 10;
    	int sum = value_a + value_b + advance;
    	if(sum >= 30)
    	{
			advance = 1;
			sum -= 30;    		
		}
		else
			advance = 0;
		s += _num30[sum];
    }
	if(advance != 0)
		s += _num30[advance];
    reverse(s.begin(), s.end());
	if(s[s.length()-1] != '0')
	{
		for(int i = 0; i < s.length(); i++)
			if(s[i] != '0')
			{
				s.erase(0, i);
				break;
			}		
	}
	else s = "0";

	cout << s << endl;
    return 0;
}
