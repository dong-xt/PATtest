#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int k;
    cin >> k;
    int n[k];
    for(int i = 0; i < k; i++)
        cin >> n[i];
    for(int i = 0; i < k; i++)
    {
        int num = n[i];
        if(num != 0)
        {
            while(num != 1)
            {
                if(num % 2 == 1)
                    num = ((3 * num) + 1) / 2;
                else
                    num /= 2;
                for(int a = 0; a < k; a++)
                    if((num == n[a]) && (a != k))
                        n[a] = 0;
            }
        }
    }
    sort(n, n + k);	
    for(int i = k - 1; i >= 0; i--)
    {
    	cout << n[i];
    	if(i-1 >= 0 && n[i-1] != 0)
    		cout << " ";
    	else
    		break;
	}
	cout << endl;
    
    return 0;
}
