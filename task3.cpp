#include <stdio.h>

typedef struct{
    int day;
    int month;
    int year;
} Date;


int Month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int checkDate(const Date* x)
{
    if (x->year < 1980 || (*x).year>2200) return -1;
    if ((*x).month < 1 || x->month>12) return -2;
    if (x->day <= 0 || (*x).day > Month[x->month - 1]) return -3;

    return 0;
}

int input(Date* x)
{
    scanf_s("%d", &x->day);
    scanf_s("%d", &x->month);
    scanf_s("%d", &x->year);
    return 0;
}

void show(const Date x)
{
    printf_s("\nYour date => %2d.%2d.%4d", x.day, x.month, x.year);
}

int leapYear(int year)
{
    if ((year % 400) == 0)
    {
        return 1;
    }
    if ((year % 100) == 0)
    {
        return 0;
    }
    if ((year % 4) == 0)
    {
        return 1;
    }
    return 0;
}

Date yesterday(const Date x)
{
    Date res = x;
    if (x.day > 1)
    {
        res.day--;
        return res;
    }

    if (x.month > 1)
    {
        res.month--;
        res.day = Month[res.month - 1];
        if (leapYear(x.year) && res.month == 2) res.day = 29;
        return res;
    }

    if (x.month == 1)
    {
        res.year--;
        res.month = 12;
        res.day = 31;
        return res;
    }
    fprintf_s(stderr, "Wrong!!!");
    return res;
}

Date tomorrow(const Date x)
{
    Date res = x;
    if (res.day < Month[x.month - 1] + ((x.month == 2) ? leapYear(x.year) : 0))
    {
        res.day++;
        return res;
    }

    if (x.month < 12)
    {
        res.month++;
        res.day = 1;
        return res;
    }

    if (x.month == 12)
    {
        res.year++;
        res.month = 1;
        res.day = 1;
        return res;
    }
    fprintf(stderr, "Wrong!!!");
    return res;
}

int day_of_week(Date x)
{
    int ans = 3;
    Date rep = { 1, 1, 1981 };
    while (!((rep.day == x.day) && (rep.month == x.month) && (rep.year == x.year)))
    {
        ans++;
        rep = tomorrow(rep);
    }
    ans %= 7;
    printf("\n");
    switch (ans)
    {
    case 0:
        printf("Monday");
        break;
    case 1:
        printf("Tuesday");
        break;
    case 2:
        printf("Wednesday");
        break;
    case 3:
        printf("Thursday");
        break;
    case 4:
        printf("Friday");
        break;
    case 5:
        printf("Saturday");
        break;
    case 6:
        printf("Sunday");
        break;
    default:
        printf("something went wrong");
        return -1;
        break;
    }
    return 0;
}


int main6()
{
    Date dat1;

    do {
        printf("input date:\n");
        input(&dat1);
        if (checkDate(&dat1) == 0) break;
    } while (1);

    show(dat1);
    day_of_week(dat1);
    printf("\nyesterday:");
    show(yesterday(dat1));
    printf("\ntomorrow:");
    show(tomorrow(dat1));

    return 0;
}