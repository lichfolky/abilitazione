#include <stdio.h>

// Definizione della struttura per l'indirizzo
typedef struct 
{
    char via[50];
    int civico;
    char citta[50];
    char provincia[3]; // Es. "MI" per Milano
    char cap[6];       // Es. "20100"
    char stato[30];    // Es. "Italia"
} Indirizzo;

// Funzione per stampare un indirizzo
void stampaIndirizzo(Indirizzo *ind)
{
    printf("Indirizzo:\n");
    printf("%s, %d\n", ind->via, ind->civico);
    printf("%s (%s) - %s\n", ind->citta, ind->provincia, ind->cap);
    printf("%s\n", ind->stato);
}

int main()
{
    // Creazione di un indirizzo di esempio
    Indirizzo casa = {
        "Via Roma",
        10,
        "Torino",
        "TO",
        "10130",
        "Italia"};

    // Stampa dell'indirizzo
    stampaIndirizzo(&casa);

    return 0;
}