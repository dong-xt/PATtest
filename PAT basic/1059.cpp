#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;

struct PEOPLE
{
    int rank;
    bool win = false;
    bool payment = false;
};

bool isprime(int a)
{
    bool res = true;
    for(int i = 2; i <= sqrt(a); i++)
    {
        if(a % i == 0)
        {
            res = false;
            break;
        }
    }
    return res;
}

int main()
{
    PEOPLE p[10000];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        p[idx].rank = i + 1;
        p[idx].win = true;
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int check;
        cin >> check;
        if(p[check].win == false)
            cout << setfill('0') << setw(4) << check << ": Are you kidding?" << endl;
        else if(p[check].payment == true)
            cout << setfill('0') << setw(4) << check << ": Checked" << endl;
        else
        {
            int _rank = p[check].rank;
            if(_rank == 1)
                cout << setfill('0') << setw(4) << check << ": Mystery Award" << endl;
            else if(isprime(_rank))
                cout << setfill('0') << setw(4) << check << ": Minion" << endl;
            else
                cout << setfill('0') << setw(4)  << check << ": Chocolate" << endl;
            p[check].payment = true;
        }
    }
    return 0;
}
