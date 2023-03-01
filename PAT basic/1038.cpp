#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt[101] = {0}; //°Ù·ÖÖÆ 0~100
    for(int i = 0; i < n; i++)
    {
        int score;
        cin >> score;
        cnt[score]++;
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int seek;
        cin >> seek;
        cout << cnt[seek];
        if(i != k - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}
