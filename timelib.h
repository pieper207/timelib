#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

    struct date
    {
        int day;
        int month;
        int year;
    };

    struct date indate;

    // Es folgen Prototypen der Unterprogramme, damit der Copiler weiß, welche Werte diese übergeben bekommen und zurückgeben.
    int day_of_the_year(indate.day, indate.month, indate.year);
    int is_leapyear(int jahr);
    int get_days_for_month(indate.month, indate.year);
    int exists_date(int day, int month, int year);
    void input_date(&(indate.day ,&(indate.month), &(indate.year));


#endif // TIMELIB_H_INCLUDED
