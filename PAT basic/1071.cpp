#include<iostream>
using namespace std;

int main()
{
    int T = 0, K = 0, n1, n2, b, t;
    cin >> T >> K;
    for(int i = 0; i < K; i++)
    {
        cin >> n1 >> b >> t >> n2;
        if(T < t)
        {
            cout << "Not enough tokens.  Total = " << T << "." << endl;
        }
        else
        {
            if(n1 > n2)
            {
                if(b == 0)
                {
                    T += t;
                    cout << "Win " << t << "!  Total = " << T << "." << endl;
                }
                else
                {
                    T -= t;
                    cout << "Lose " << t << ".  Total = " << T << "." << endl;                
                }
            }
            else
            {
                if(b == 1)
                {
                    T += t;
                    cout << "Win " << t << "!  Total = " << T << "." << endl;                
                }
                else
                {
                    T -= t;
                    cout << "Lose " << t << ".  Total = " << T << "." << endl;                    
                }
            }            
        }
        if(T <= 0)
        {
            cout << "Game Over." << endl;
            break;
        }
    }
    return 0;
}
