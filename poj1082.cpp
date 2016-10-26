#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAX_D = 365 * 105;
const int eM[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class date {
    public:
        int year;
        int month;
        int day;
        date() {}
        date(int year, int month, int day) : year(year), month(month), day(day) {}
        bool operator < (const date &other) const{
            return this->year != other.year? this->year < other.year : this->month != other.month?
                    this->month < other.month : this->day < other.day;
        }
};

bool isLeapYear(int year) {
    return (year % 400 == 0) || ((year % 100 > 0) && (year % 4 == 0));
}

int D = 0;
date days[MAX_D];
bool win[MAX_D] = {true};

void init_calendar() {
    for(int year = 1900; year <= 2001; year++) {
        for(int month = 0; month < 12; month++) {
            for(int day = 0, eD = eM[month] + ((day == 1 && isLeapYear(year))? 1 : 0); day < eD; day++)
                days[D++] = date(year, month, day);
        }
    }
}

void solve() {
    for(int i = 0; i < MAX_D; i++)
        win[i] = true;
    int start = lower_bound(days, days + D, date(2001, 10, 3)) - days;
    win[start] = false;
    for(int i = start - 1; i >= 0; i--) {
        win[i] = false;
        if(win[i + 1] == false) {
            win[i] = true;
            continue;
        }
        else {
            date nextM = days[i];
            nextM.month++;
            if(nextM.month == 12) {
                nextM.month = 0;
                nextM.year++;
            }
            if(binary_search(days, days + D, nextM) &&
                win[lower_bound(days, days + D, nextM) - days] == false)
                win[i] = true;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    init_calendar();
    solve();
    while(T--) {
        int year, month, day;
        scanf("%d %d %d", &year, &month, &day);
        month--;
        day--;
        date dt(year, month, day);
        puts(win[lower_bound(days, days + D, dt) - days] == true? "YES" : "NO");
    }
    return 0;
}
//No. 75
