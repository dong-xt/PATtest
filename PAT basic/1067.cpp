#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s = "", s_gold;
    int n;
    cin >> s_gold >> n;
    cin.ignore(10, '\n');
    bool end = false;
    int cnt = 0;
    getline(cin, s);
    while(s.compare("#") != 0)
    {
        if(!end)
        {
            if(s.compare(s_gold) == 0)
            {
                cout << "Welcome in" << endl;
                end = true;
            }
            else
            {
                cout << "Wrong password: " << s << endl;
                cnt++;
            }
            if(cnt >= n)
            {
                cout << "Account locked" << endl;
                end = true;
            }
        }
        getline(cin, s);
    }
    return 0;
}
