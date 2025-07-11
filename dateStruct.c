#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

int compareDates(struct Date *date1, struct Date *date2);
void printDate(struct Date *date);
int isLeapYear(int year);
int daysInMonth(int month, int year);
void addOneDay(struct Date *date);
int isValidDate(struct Date *date);
void printStagione(struct Date *date);
void stampaGiornoSettimana(struct Date *date);

int main()
{
    // TESTING
    struct Date oggi = {28, 2, 2004};
    struct Date domani = {29, 2, 2004};
    printDate(&oggi);
    printf("%d\n", isLeapYear(2004));
    addOneDay(&oggi);
    printDate(&oggi);
    printf("%d\n", compareDates(&oggi, &domani));
    return 0;
}

int compareDates(struct Date *date1, struct Date *date2)
{
    if (date1->year != date2->year)
    {
        return date1->year - date2->year;
    }
    if (date1->month != date2->month)
    {
        return date1->month - date2->month;
    }
    return date1->day - date2->day;
}

void printDate(struct Date *date)
{
    const char *monthsNames[] = {"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"};

    printf("%d %s %d\n", date->day, monthsNames[date->month - 1], date->year);
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

void addOneDay(struct Date *date)
{
    date->day++;

    // Se ultimo giorno mese
    if (date->day > daysInMonth(date->month, date->year))
    {
        date->day = 1;
        date->month++;

        // Controlla anno nuovo
        if (date->month > 12)
        {
            date->month = 1;
            date->year++;
        }
    }
}

// ALTRE SEMPLICI FUNZIONI POSSIBILI
int isValidDate(struct Date *date)
{
    // TODO
    return 0;
}
void stampaStagione(struct Date *date)
{
    // TODO
}

void stampaGiornoSettimana(struct Date *date)
{
    // possibile aggiunta https://it.wikipedia.org/wiki/Congruenza_di_Zeller
    // per calcolo giorno della settimana
}

int main()
{
    // TESTING
    struct Date oggi = {28, 2, 2004};
    struct Date domani = {29, 2, 2004};
    printDate(&oggi);
    printf("%d\n", isLeapYear(2004));
    addOneDay(&oggi);
    printDate(&oggi);
    printf("%d\n", compareDates(&oggi, &domani));
    return 0;
}
