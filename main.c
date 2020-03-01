#include <stdio.h>
#include <stdlib.h>

/*
    Name: Sarah Pieper
    Klasse: ifa 92
    Bearbeitungszeitraum: 11.01.2020-01.03.2020
    Nutzen des Programms: Das Programm berechnet nach Eingabe eines Datums,
    wieviele Tage im Jahr, f�r die Eingabe, schon vergangen sind, sowie die
    Tageanzahl des eingegebenen Monats.

*/

    // Es folgen Prototypen der Unterprogramme, damit der Copiler wei�, welche Werte diese �bergeben bekommen und zur�ckgeben.
    int day_of_the_year(int day, int month, int year);
    int is_leapyear(int jahr);
    int get_days_for_month(int month, int year);
    int exists_date(int *day, int *month, int *year);
    void input_date(int *day, int *month, int *year);


int main()      // Das Programm. Hier werden die Unterprogramme aufgerufen und die Ergebnisse ausgegeben.
{
    int day = 0;        // Dekleration und Initialisierung dreier Variablen, die immer wieder gebraucht werden
    int month = 0;
    int year = 0;
    int dayOfTtheYear;
    int dayOfTtheMonth;

    input_date(&day ,&month, &year); // Hier wird die Adresse anstatt einer Kopie �bergeben, damit vom Unterprogramm aus der Wert im Hauptprogramm ge�ndert werden kann.
    dayOfTtheYear = day_of_the_year(day,month,year);
    dayOfTtheMonth = get_days_for_month(month, year);
    printf("Die Anzahl der vergangenen Tage lautet: %d \n",dayOfTtheYear);
    printf("Der Monat hat %d Tage",dayOfTtheMonth);

    return 0;
}

int day_of_the_year(int day, int month, int year)   // Die Funktion berechnet f�r ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag,
{                                                   // Monat und Jahr die Nummer des Tages, gez�hlt von Jahresbeginn (1. Januar) an.
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    int ergebnis = 0;
    int schaltjahr;
    schaltjahr = is_leapyear(year);

    if (schaltjahr == 1)        // Abfrage ob das Jahr ein Scahltjahr ist, damit in der folgenden Schleife kein Tag fehlt/ zu viel berechnet wird.
    {
        days[1] = 29;
    }
    for(i = 0; i < month -1; i++)
    {
        ergebnis += days[i];    // Bei jedem Durchlauf werden die Tage des Monats auf 'ergebnis' addiert, aber nur bis zum vorherigen Monat des
                                // eingegebenen Monats.
    }
    ergebnis += day;        // Nun wird nur noch die Tag-Anzahl (die zu Begin eigegeben wurde) auf 'ergebnis' addiert.

    return ergebnis;
}


int is_leapyear(int year)   // Die Funktion �berpr�ft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr ist
{
    if ((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0))
    {
        year = 1;
    }
    if(year < 1582)
    {
        year = -1;
    }
    else
    {
        year = 0;
    }

    return year;
}

int get_days_for_month(int month, int year) // Die Funktion bestimmt f�r einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat.
{
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    int resultMonth = 0;
    int leapYear;
    leapYear = is_leapyear(year);

    if (leapYear == 1)
    {
        days[1] = 29;
    }

    for(i = 0; i < month ; i++)      // Die Schleife z�hlt 'i' solange hoch, bis sie beim aktuellen Monat angekommen ist.
    {
        resultMonth = days[i];       // Die Tage des aktuellen Monats werden in 'resultMonth' geschrieben.
    }

    return resultMonth;
}

int exists_date(int *day, int *month, int *year)  // Die Funktion �berpr�ft, ob ein eingegebenes Datum g�ltig ist.
{
    int i;
    int valid;
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

   for(i = 0; i < month; i++)
    {
        if(*day > days[i])
        {
            valid = 0;
        }
        else
        {
            break;
        }
    }

    if((*month < 1) || (*day < 1) || (*year < 1582) || (*year > 2400) || (*month > 12))     // Abfrage zur G�ltigkeit des Datums.
    {
        valid = 0;
    }
    else
    {
        valid = 1;
    }

    return valid;
}

void input_date(int *day, int *month, int *year) // Zeigt auf die Stelle im Hauptprogramm.
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

    trueOrFalse = exists_date(day, month, year); // Das Unterprogramm 'exists_date' liefert die G�ltigkeit und wird in 'trueOrFalse' geschrieben.
    }while(trueOrFalse == 0);
}
