#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string month;
        cin >> month;
        if(month == "Jan") month = "01";
        else if(month == "Feb") month = "02";
        else if(month == "Mar") month = "03";
        else if(month == "Apr") month = "04";
        else if(month == "May") month = "05";
        else if(month == "Jun") month = "06";
        else if(month == "Jul") month = "07";
        else if(month == "Aug") month = "08";
        else if(month == "Sep") month = "09";
        else if(month == "Oct") month = "10";
        else if(month == "Nov") month = "11";
        else if(month == "Dec") month = "12";
        string day;
        cin >> day;
        day.erase(day.length()-1, 1);
        if(day.length() == 1) day = '0' + day;
        string year;
        cin >> year;
        string addition = "0000";
        year = addition.substr(0, 4 - year.length()) + year;
        string back = month + day;
        string date = year + back;
        reverse(back.begin(), back.end());
        if(year == back)
            cout << "Y " << date << endl;
        else
            cout << "N " << date << endl;
    }
    return 0;
}
