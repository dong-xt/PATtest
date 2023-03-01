#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string name_max, name_min;
    string id_max, id_min;
    int score_max = -1, score_min = 101;
    for(int i = 0; i < n; i++)
    {
        string name, id;
        int score;
        cin >> name >> id >> score;
        if(score > score_max)
        {
            score_max = score;
            name_max = name;
            id_max = id;
        }
        if(score < score_min)
        {
            score_min = score;
            name_min = name;
            id_min = id;
        }
    }
    cout << name_max << " " << id_max << endl;
    cout << name_min << " " << id_min << endl;
    return 0;
}
