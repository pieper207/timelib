#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

int day_of_the_year(struct date indate)   // Die Funktion berechnet f�r ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag,
{                                                   // Monat und Jahr die Nummer des Tages, gez�hlt von Jahresbeginn (1. Januar) an.
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    int ergebnis = 0;
    int schaltjahr;
    schaltjahr = is_leapyear(indate.year);

    if (schaltjahr == 1)        // Abfrage ob das Jahr ein Scahltjahr ist, damit in der folgenden Schleife kein Tag fehlt/ zu viel berechnet wird.
    {
        days[1] = 29;
    }
    for(i = 0; i < date.month -1; i++)
    {
        ergebnis += days[i];    // Bei jedem Durchlauf werden die Tage des Monats auf 'ergebnis' addiert, aber nur bis zum vorherigen Monat des
                                // eingegebenen Monats.
    }
    ergebnis += date.day;        // Nun wird nur noch die Tag-Anzahl (die zu Begin eigegeben wurde) auf 'ergebnis' addiert.

    return ergebnis;
}


int is_leapyear(struct date indate)   // Die Funktion �berpr�ft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr ist
{
    if ((date.year % 4 == 0) && (date.year % 100 == 0) && (date.year % 400 == 0))
    {
        date.year = 1;
    }
    if(date.year < 1582)
    {
        date.year = -1;
    }
    else
    {
        date.year = 0;
    }

    return date.year;
}

int get_days_for_month(struct date indate) // Die Funktion bestimmt f�r einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat.
{
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    int resultMonth = 0;
    int leapYear;
    leapYear = is_leapyear(date.year);

    if (leapYear == 1)
    {
        days[1] = 29;
    }

    for(i = 0; i < date.month ; i++)      // Die Schleife z�hlt 'i' solange hoch, bis sie beim aktuellen Monat angekommen ist.
    {
        resultMonth = days[i];       // Die Tage des aktuellen Monats werden in 'resultMonth' geschrieben.
    }

    return resultMonth;
}

int exists_date(struct date indate)  // Die Funktion �berpr�ft, ob ein eingegebenes Datum g�ltig ist.
{
    int i;
    int valid;
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

   for(i = 0; i < indate.month; i++)
    {
        if(indate.day > days[i])
        {
            valid = 0;
        }
        else
        {
            break;
        }
    }

    if((indate.month < 1) || (indate.day < 1) || (indate.year < 1582) || (indate.year > 2400) || (indate.month > 12))     // Abfrage zur G�ltigkeit des Datums.
    {
        valid = 0;
    }
    else
    {
        valid = 1;
    }

    return valid;
}

void input_date(struct date *indate) // Zeigt auf die Stelle im Hauptprogramm.
{                                                // Die Funktion liest 3 Ganzzahlwerte (Integer) ein, f�r Tag, Monat und Jahr. Wenn das angegebene
                                                // Datum ung�ltig ist, wird erneut eingelesen, solange bis ein g�ltiges Datum eingegeben wurde.

    int trueOrFalse;

    do // Wenn das Datum ung�ltig ist, wird es erneut eingegeben.
    {
    printf("Bitte geben Sie den Tag und den Monat ohne eine 0 davor ein!\n\n"); //Hinweis zur korrekten Eingabe.
    printf("Bitte Tag eingeben: \n");           //Eingabe des Tages.
    scanf("%d", day);                           // kein & ben�tigt das dieses beim �bergeben der Variablen verwendet wird und ein Zeiger im Unterprogramm darauf zeigt.

    printf("Bitte Monat eingeben: \n");         // Eingabe des Monats.
    scanf("%d", month);

    printf("Bitte Jahr eingeben: \n");          // Eingabe des Jahres.
    scanf("%d", year);

    trueOrFalse = exists_date(*day, *month, *year); // Das Unterprogramm 'exists_date' liefert die G�ltigkeit und wird in 'trueOrFalse' geschrieben.
    }while(trueOrFalse == 0);
}

