#include <stdio.h>

void addOneDay(int *pDay, int *pMonth, int *pYear);
int compareDates(int day1, int month1, int year1, int day2, int month2, int year2);
int *lastDayMonth(int month, int year);

void printDate(int day, int month, int year);
int isLeapYear(int year);
int daysInMonth(int month, int year);
int isValidDate(int day, int month, int year);
void stampaStagione(int day, int month, int year);
void stampaGiornoSettimana(int day, int month, int year);

int main()
{
    int day = 28;
    int month = 2;
    int year = 2004;
    int day1 = 29;
    int month1 = 2;
    int year1 = 2004;

    // TESTING
    printDate(day, month, year);
    printf("%d\n", isLeapYear(2004));
    addOneDay(&day, &month, &year);
    printDate(day, month, year);
    printDate(day1, month1, year1);
    printf("%d\n", compareDates(day, month, year, day1, month1, year1));
    int *res = lastDayMonth(month, year);
    int day2 = res[0];
    int month2 = res[1];
    int year2 = res[2];
    printDate(day2, month2, year2);
    return 0;
}

void addOneDay(int *pDay, int *pMonth, int *pYear)
{
    (*pDay)++;

    // Se ultimo giorno mese
    if ((*pDay) > daysInMonth((*pMonth), (*pYear)))
    {
        (*pDay) = 1;
        (*pMonth)++;

        // Controlla anno nuovo
        if ((*pMonth) > 12)
        {
            (*pMonth) = 1;
            (*pYear)++;
        }
    }
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

int *lastDayMonth(int month, int year)
{
    static int newDay[3];
    newDay[0] = daysInMonth(month, year);
    newDay[1] = month;
    newDay[2] = year;
    return newDay;
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
