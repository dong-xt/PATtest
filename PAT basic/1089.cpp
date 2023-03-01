#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int speech[n];
    for(int i = 0; i < n; i++)
        cin >> speech[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            bool lie[n];
            fill(lie, lie + n, false);
            int lie_cnt = 0;
            for(int k = 0; k < n; k++)
            {
                if(speech[k] > 0 && (speech[k] == i || speech[k] == j))
                {
                    lie[k] = true;
                    lie_cnt++;
                }
                else if(speech[k] < 0 && speech[k] != -1 * i && speech[k] != -1 * j)
                {
                    lie[k] = true;
                    lie_cnt++;
                }
            }
            if(lie_cnt == 2 && (lie[i-1] ^ lie[j-1]))
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "No Solution" << endl;
    return 0;
}
