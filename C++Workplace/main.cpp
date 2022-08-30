#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<math.h>

#include<time.h>

long long get_days(const char* from, const char* to);

time_t convert(int year,int month,int day);

int main()

{

    const char* from="1983-01-08";

    const char* to="2074-09-12";

    long long days=get_days(from,to);

    printf("From:%s\nTo:%s\n",from,to);

    printf("%lld\n",days);

    system("pause");

    return 0;

}

time_t convert(int year,int month,int day)

{

    tm info={0};

    info.tm_year=year-1900;

    info.tm_mon=month-1;

    info.tm_mday=day;

    return mktime(&info);

}

long long get_days(const char* from, const char* to)

{

    int year,month,day;

    sscanf(from,"%d-%d-%d",&year,&month,&day);

    long long fromSecond=convert(year,month,day);

    sscanf(to,"%d-%d-%d",&year,&month,&day);

    long long toSecond=convert(year,month,day);

    return (toSecond-fromSecond)/24/3600;

}