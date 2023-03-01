#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string id[n];
    int pos[n];
    for(int i = 0; i < n ; i++)
    {
        string s;
        int _index, index;
        cin >> s >> _index >> index;
        id[_index - 1] = s;
        pos[_index - 1] = index;
    }
    int num = 0;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        int search;
        cin >> search;
        cout << id[search - 1] << " " << pos[search - 1] << endl;
    }
    return 0;
}
