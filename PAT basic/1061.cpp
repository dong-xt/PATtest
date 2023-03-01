#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int grade[m];
    int answer[m];
    for(int i = 0; i < m; i++)
        cin >> grade[i];
    for(int i = 0; i < m; i++)
        cin >> answer[i];
    int score = 0;
    for(int i = 0; i < n; i++)
    {
        score = 0;
        for(int j = 0; j < m; j++)
        {
            int ans;
            cin >> ans;
            if(ans == answer[j])
            {
                score += grade[j];
            }            
        }
        cout << score << endl;
    }
    return 0;
}
