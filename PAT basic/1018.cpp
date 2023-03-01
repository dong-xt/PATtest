#include<iostream>
using namespace std;

bool judge(char a, char b)
{
    if(a == 'C' && b == 'J')
        return true;
    else if(a == 'C' && b == 'B')
        return false;
    else if(a == 'J' && b == 'C')
        return false;
    else if(a == 'J' && b == 'B')
        return true;
    else if(a == 'B' && b == 'C')
        return true;
    else if(a == 'B' && b == 'J')
        return false;
}

int max_3(int a, int b, int c)
{
    a = (a < b) ? b : a;
    a = (a < c) ? c : a;
    return a;
}

char max_seek(int c, int j, int b)
{
    if(b == max_3(c, j, b))
        return 'B';
    else if(c == max_3(c, j, b) && c != b)
        return 'C';
    else if(j == max_3(c, j, b) && j != c && j != b)
        return 'J';
}

int main()
{
    int n;
    cin >> n;
    int x = 0, y = 0, z = 0;
    int c_win_a = 0, j_win_a = 0, b_win_a = 0;
    int c_win_b = 0, j_win_b = 0, b_win_b = 0;
    for(int i = 0; i < n; i++)
    {
        char a, b;
        cin >> a >> b;
        if(a == b)  //Æ½
            y++;
        else if(judge(a, b)) //¼×Ó®
        {
            x++;
            if(a == 'C') c_win_a++;
            else if(a == 'J') j_win_a++;
            else if(a == 'B') b_win_a++;
        }
        else
        {
            z++;
            if(b == 'C') c_win_b++;
            else if(b == 'J') j_win_b++;
            else if(b == 'B') b_win_b++;            
        }
    }
    cout << x << " " << y << " " << z << endl;
    cout << z << " " << y << " " << x << endl;
    cout << max_seek(c_win_a, j_win_a, b_win_a) << " " << max_seek(c_win_b, j_win_b, b_win_b) << endl;
    return 0;
}
