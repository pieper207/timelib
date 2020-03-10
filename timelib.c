#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

int day_of_the_year(struct date indate)   // Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag,
{                                                   // Monat und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an.
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    int ergebnis = 0;
    int leapyear;
    leapyear = is_leapyear(indate);

    if (leapyear == 1)        // Abfrage ob das Jahr ein Scahltjahr ist, damit in der folgenden Schleife kein Tag fehlt/ zu viel berechnet wird.
    {
        days[1] = 29;
    }
    for(i = 0; i < indate.month -1; i++)
    {
        ergebnis += days[i];    // Bei jedem Durchlauf werden die Tage des Monats auf 'ergebnis' addiert, aber nur bis zum vorherigen Monat des
                                // eingegebenen Monats.
    }
    ergebnis += indate.day;        // Nun wird nur noch die Tag-Anzahl (die zu Begin eigegeben wurde) auf 'ergebnis' addiert.

    return ergebnis;
}


int is_leapyear(struct date indate)   // Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr ist
{
    if ((indate.year % 4 == 0) && (indate.year % 100 != 0) || (indate.year % 400 == 0))
    {
        indate.year = 1;
    }
    else if(indate.year < 1582)
    {
        indate.year = -1;
    }
    else
    {
        indate.year = 0;
    }

    return indate.year;
}

int get_days_for_month(struct date indate) // Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat.
{
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    int resultMonth = 0;
    int leapYear;
    leapYear = is_leapyear(indate);

    if (leapYear == 1)
    {
        days[1] = 29;
    }

    for(i = 0; i < indate.month ; i++)      // Die Schleife zählt 'i' solange hoch, bis sie beim aktuellen Monat angekommen ist.
    {
        resultMonth = days[i];       // Die Tage des aktuellen Monats werden in 'resultMonth' geschrieben.
    }

    return resultMonth;
}

int exists_date(struct date indate)  // Die Funktion überprüft, ob ein eingegebenes Datum gültig ist.
{
    int i;
    int valid;
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int daysOfMonth = get_days_for_month(indate);

    if((indate.month < 1) || (indate.day < 1) || (indate.year < 1582) || (indate.year > 2400) || (indate.month > 12) || (indate.day > daysOfMonth))     // Abfrage zur Gültigkeit des Datums.
    {
        valid = 0;
    }
    else
    {
        valid = 1;
    }

    return valid;
}

struct date input_date() // Zeigt auf die Stelle im Hauptprogramm.
{                                                // Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene
    struct date indate;
                                             // Datum ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.

    int trueOrFalse;

    do // Wenn das Datum ungültig ist, wird es erneut eingegeben.
    {
    printf("Bitte geben Sie den Tag und den Monat als Zahl an!\n\n"); //Hinweis zur korrekten Eingabe.
    printf("Bitte Tag eingeben: \n");           //Eingabe des Tages.
    scanf("%d", &(indate.day));                           // kein & benötigt das dieses beim Übergeben der Variablen verwendet wird und ein Zeiger im Unterprogramm darauf zeigt.

    printf("Bitte Monat eingeben: \n");         // Eingabe des Monats.
    scanf("%d", &(indate.month));

    printf("Bitte Jahr eingeben: \n");          // Eingabe des Jahres.
    scanf("%d", &(indate.year));

    trueOrFalse = exists_date(indate); // Das Unterprogramm 'exists_date' liefert die Gültigkeit und wird in 'trueOrFalse' geschrieben.
    }while(trueOrFalse == 0);
    return indate;
}

