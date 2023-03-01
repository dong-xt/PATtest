#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool simplest(int a, int b)
{
    int min = (a > b) ? b : a;
    for(int i = 2; i <= min; i++)
    {
        if(a % i == 0 && b % i == 0)
            return false;
    }        
    return true;
}

int main()
{
    string s1, s2;
    int k;
    cin >> s1 >> s2 >> k;
    int pos1 = s1.find('/'); 
    int pos2 = s2.find('/');
    int up1 = stoi(s1.substr(0, pos1)); 
	int down1 = stoi(s1.substr(pos1 + 1, s1.length() - 1 - pos1));
    int up2 = stoi(s2.substr(0, pos2)); 
	int down2 = stoi(s2.substr(pos2 + 1, s2.length() - 1 - pos2));
    if((double)up1/down1 > (double)up2/down2)
    {
        int t1 = up1; up1 = up2; up2 = t1;
        t1 = down1; down1 = down2; down2 = down1;
    }
    int _up1 = k * up1; int _up2 = k * up2;
    int up = 1;
    bool first = true;
    while(true)
    {
        if(up * down1 > _up1 && up * down2 < _up2)
        {   
            if(simplest(up, k))
            {
                if(!first) cout << " ";
                else first = false;
                cout << up << "/" << k;
            }
        }
        else if(up * down2 > _up2)
            break;
        up++;
    }
    cout << endl;
    return 0;
}
