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
    int day_of_the_year(struct date indate);
    int is_leapyear(struct date indate);
    int get_days_for_month(struct date indate);
    int exists_date(struct date indate);
    struct date input_date();


#endif // TIMELIB_H_INCLUDED
