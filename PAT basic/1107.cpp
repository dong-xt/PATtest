#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int fatmax = -1;
    for(int i = 0; i < n; i++)
    {
        int fat = -1;
        for(int j = 0; j < m; j++)
        {
            int weight;
            cin >> weight;
            if(weight > fat) fat = weight;
            if(weight > fatmax) fatmax = weight;
        }
        if(i != 0) cout << " ";
        cout << fat;
    }
    cout << endl;
    cout << fatmax << endl;
    return 0;
}
