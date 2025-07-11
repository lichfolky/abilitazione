#include <stdio.h>

#include <stdio.h>

int compareDates(int day1, int month1, int year1, int day2, int month2, int year2);
void printDate(int day, int month, int year);
int isLeapYear(int year);
int daysInMonth(int month, int year);
void addOneDay(int day, int month, int year);
int isValidDate(int day, int month, int year);
void stampaStagione(int day, int month, int year);
void stampaGiornoSettimana(int day, int month, int year);

int main()
{
    // TESTING
    printDate(28, 2, 2004);
    printf("%d\n", isLeapYear(2004));
    addOneDay(28, 2, 2004);
    printDate(28, 2, 2004);
    printf("%d\n", compareDates(28, 2, 2004, 29, 2, 2004));
    return 0;
}

int compareDates(int day1, int month1, int year1, int day2, int month2, int year2)
{
    if (year1 != year2)
    {
        return year1 - year2;
    }
    if (month1 != month2)
    {
        return month1 - month2;
    }
    return day1 - day2;
}

void printDate(int day, int month, int year)
{
    const char *monthsNames[] = {"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"};

    printf("%d %s %d\n", day, monthsNames[month - 1], year);
}

int isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year)
{
    // Febbraio
    if (month == 2)
    {
        return 28 + isLeapYear(year);
    }
    //  30 giorni Novembre, Aprile, Giugno, Settembre
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    // tutti gli altri ne hanno 31

    return 31;
}

void addOneDay(int day, int month, int year)
{
    day++;

    // Se ultimo giorno mese
    if (day > daysInMonth(month, year))
    {
        day = 1;
        month++;

        // Controlla anno nuovo
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
}

// ALTRE SEMPLICI FUNZIONI POSSIBILI
int isValidDate(int day, int month, int year)
{
    // TODO
    return 0;
}
void stampaStagione(int day, int month, int year)
{
    // TODO
}

void stampaGiornoSettimana(int day, int month, int year)
{
    // possibile aggiunta https://it.wikipedia.org/wiki/Congruenza_di_Zeller
    // per calcolo giorno della settimana
}
