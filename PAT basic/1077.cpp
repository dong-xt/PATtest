#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int teacher = 0, cnt = 0;
        int stu[n - 1];
        cin >> teacher;
        for(int j = 0; j < n - 1; j++)
        {
            int score;
            cin >> score;
            if(score >= 0 && score <= m)
            {
                stu[cnt] = score;
                cnt++;
            }
        }
        sort(stu, stu + cnt);
        int sum = 0;
        for(int j = 1; j < cnt - 1; j++)
        {
            sum += stu[j];
        }
        int g = 0.5 + ((float)teacher + (float)sum/(cnt - 2)) / 2;
        cout << g << endl;
    }
    return 0;
}
