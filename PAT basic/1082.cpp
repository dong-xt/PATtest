#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string champion, chick;
    int min = 100000, max = 0;
    for(int i = 0; i < n; i++)
    {
        string s;
        int x, y;
        cin >> s >> x >> y;
        int dis = abs(x) * abs(x) + abs(y) + abs(y);
        if(dis < min)
        {
            champion = s;
            min = dis;
        }
        if(dis > max)
        {
            chick = s;
            max = dis;
        }
    }
    cout << champion << " " << chick << endl;
    return 0;
}
