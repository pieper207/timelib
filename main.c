#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

/*
    Name: Sarah Pieper
    Klasse: ifa 92
    Bearbeitungszeitraum: 11.01.2020-01.03.2020
    Nutzen des Programms: Das Programm berechnet nach Eingabe eines Datums,
    wieviele Tage im Jahr, für die Eingabe, schon vergangen sind, sowie die
    Tageanzahl des eingegebenen Monats.

*/

int main()      // Das Programm. Hier werden die Unterprogramme aufgerufen und die Ergebnisse ausgegeben.
{
    struct date indate;        // Dekleration und Initialisierung dreier Variablen, die immer wieder gebraucht werden
    int dayOfTtheYear;
    int dayOfTtheMonth;

    input_date(&(indate.day ,&(indate.month), &(indate.year)); // Hier wird die Adresse anstatt einer Kopie übergeben, damit vom Unterprogramm aus der Wert im Hauptprogramm geändert werden kann.
    dayOfTtheYear = day_of_the_year(indate.day, indate.month, indate.year);
    dayOfTtheMonth = get_days_for_month(indate.month, indate.year);
    printf("Die Anzahl der vergangenen Tage lautet: %d \n", dayOfTtheYear);
    printf("Der Monat hat %d Tage",dayOfTtheMonth);

    return 0;
}
