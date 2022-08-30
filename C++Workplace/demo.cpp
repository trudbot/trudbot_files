#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        if(date1 < date2) {
            return daysBetweenDates(date2, date1);
        }
        struct tm t1 = {0}, t2 = {0};
        sscanf(date1.c_str(), "%d-%d-%d", &t1.tm_year, &t1.tm_mon, &t1.tm_mday);
        sscanf(date2.c_str(), "%d-%d-%d", &t2.tm_year, &t2.tm_mon, &t2.tm_mday);

        t1.tm_year -= 1900, t2.tm_year -= 1900;
        t1.tm_mon --, t2.tm_mon --;

        return (mktime(&t1) - mktime(&t2)) / (24 * 3600);
    }
};

int main() {

    Solution s;
    cout << s.daysBetweenDates("1983-01-08", "2074-09-12");
    return 0;
}