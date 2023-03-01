#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int line[n];
    for(int i = 0; i < n; i++)
        cin >> line[i];
    sort(line, line + n);
    double len = (double)(line[0] + line[1]) / 2;
    for(int i = 2; i < n; i++)
        len = (double)(len + line[i]) / 2;
    long lenmax = (long)len;
    cout << lenmax << endl;
    return 0;
}
