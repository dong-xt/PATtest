#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int grade[1001] = {0};
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        string s;
        int score;
        cin >> s >> score;
        int pos = s.find('-');
        int idx = stoi(s.substr(0, pos));
        grade[idx] += score;
    }
    int max_grade = 0, max_idx;
    for(int i = 1; i < 1001; i++)
    {
        if(grade[i] > max_grade)
        {
            max_grade = grade[i];
            max_idx = i;
        }
    }
    cout << max_idx << " " << max_grade << endl;
    return 0;
}
