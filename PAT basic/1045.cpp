#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
    cin >> n;
    int a[n], b[n], c[n];
    int lmax = 0, cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++)
    {
        if(a[i] == b[i] && b[i] > lmax)
        {   //相等数不满足主元条件，应该筛除，但并不影响ac结果
            if(i > 0 && i < n - 1 && (a[i + 1] == b[i] || a[i - 1] == b[i]))
            {
            }
            else
            {
                c[cnt] = b[i];
                cnt++;
                lmax = b[i];
            }
        }
        else
        {
            if(b[i] > lmax)
                lmax = b[i];
        }
    }
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++)
    {
        if(i != 0) cout << " ";
        cout << c[i];
    }
    cout << endl;
    
    return 0;
}
